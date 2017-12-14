#include "platform\windows\Window_win32.hpp"

#include <memory>

#include "util\logger\Logger.hpp"
#include "common.hpp"
#include "platform\windows\KeyCodeTranslator_win32.hpp"
#include "event\events.hpp"

namespace silver::core
{
	const char* WINDOW_CLASS_NAME = "silver-window";

	HINSTANCE Window_win32::s_hInstance_ = nullptr;
	std::map<HWND, Window_win32*> Window_win32::s_handles_;
	bool Window_win32::s_windowRegistered = false;

	Window_win32::Window_win32(const WindowSettings& settings) : Window_API(settings) {}
	
	Window_win32::~Window_win32()
	{
		if (hRC_)
		{
			context_.release();
		}

		if (hDC_ && !ReleaseDC(hWnd_, hDC_))
		{
			Logger::instance().log_error("Unable to release the device context.");
		}

		if (hWnd_ && !DestroyWindow(hWnd_))
		{
			Logger::instance().log_error("Unable to destory the window.");
		}

		if (s_windowRegistered && !UnregisterClass(WINDOW_CLASS_NAME, s_hInstance_))
		{
			Logger::instance().log_error("Unable to unrigister the window class.");
		}
	}

	void Window_win32::create()
	{
		get_applicationHandle_();
		register_windowClass_();
		create_window_();
		get_deviceContext_();
		set_pixelFormatDescriptor_();
		create_renderingContext_();
	}

	void Window_win32::show(const bool state)
	{
		if (state)
		{
			ShowWindow(hWnd_, SW_SHOW);
			settings_.show = true;
			SetFocus(hWnd_);
			settings_.focus = true;
		}
		else
		{ 
			ShowWindow(hWnd_, SW_HIDE);
			settings_.show = false;
			settings_.focus = false;
		}
	}

	void Window_win32::update()
	{
		MSG msg;
		while (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE) > 0)
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	void Window_win32::focus(const bool state) noexcept
	{
		settings_.focus = state;
		if (state)
			SetFocus(hWnd_);
	}

	vec2ui Window_win32::mouse_position() const noexcept
	{
		POINT pos;
		GetCursorPos(&pos);
		ScreenToClient(hWnd_, &pos);
		return { static_cast<unsigned int>(pos.x), static_cast<unsigned int>(pos.y) };
	}

	void Window_win32::set_width(const unsigned int value) noexcept
	{
		settings_.size.x = value;
		SetWindowPos(hWnd_, nullptr, 0, 0, value, height(), SWP_NOMOVE);
	}

	void Window_win32::set_height(const unsigned int value) noexcept
	{
		settings_.size.y = value;
		SetWindowPos(hWnd_, nullptr, 0, 0, width(), value, SWP_NOMOVE);
	}

	void Window_win32::set_size(const vec2ui size) noexcept
	{
		settings_.size = size;
		SetWindowPos(hWnd_, nullptr, 0, 0, width(), height(), SWP_NOMOVE);
	}

	void Window_win32::set_title(const std::string& title) noexcept
	{
		settings_.title = title;
		SetWindowText(hWnd_, title.c_str());
	}

	Window_win32* Window_win32::get_window(const HWND& hwnd)
	{
		return s_handles_[hwnd];
	}

	void Window_win32::get_applicationHandle_()
	{
		s_hInstance_ = GetModuleHandle(nullptr);
		if (!s_hInstance_)
		{
			throw SILVER_EXCEPTION_CRITICAL("Unable to get the window handle.");
		}
	}

	void Window_win32::register_windowClass_()
	{
		WNDCLASS windowClass { 0 };
		windowClass.lpszClassName = WINDOW_CLASS_NAME;
		windowClass.style = CS_GLOBALCLASS | CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
		windowClass.hInstance = s_hInstance_;
		windowClass.hIcon = LoadIcon(nullptr, IDI_APPLICATION);
		windowClass.hCursor = LoadCursor(nullptr, IDC_ARROW);
		windowClass.lpfnWndProc = static_cast<WNDPROC>(Window_win32::windowProc_callback);

		if (!RegisterClass(&windowClass))
		{
			throw SILVER_EXCEPTION_CRITICAL("Unable to register the window class.");
		}
		s_windowRegistered = true;
	}

	void Window_win32::create_window_()
	{
		RECT rect {};
		rect.left = 0;
		rect.top = 0;
		rect.right = settings_.size.x;
		rect.bottom = settings_.size.y;

		DWORD dwStyle = WS_CLIPCHILDREN | WS_CLIPSIBLINGS | WS_OVERLAPPEDWINDOW;
		DWORD dwExStyle = WS_EX_APPWINDOW | WS_EX_WINDOWEDGE;
		AdjustWindowRectEx(&rect, dwStyle, false, dwExStyle);

		int windowX = (GetSystemMetrics(SM_CXSCREEN) - settings_.size.x) / 2;
		int windowY = (GetSystemMetrics(SM_CYSCREEN) - settings_.size.y) / 2;
		hWnd_ = CreateWindowExA(dwExStyle, WINDOW_CLASS_NAME, settings_.title.c_str(), dwStyle, windowX, windowY, settings_.size.x, settings_.size.y, nullptr, nullptr, s_hInstance_, nullptr);
		
		if (!hWnd_)
		{
			throw SILVER_EXCEPTION_CRITICAL("Unable to create the window.");
		}
		s_handles_[hWnd_] = this;
	}

	void Window_win32::get_deviceContext_()
	{
		hDC_ = GetDC(hWnd_);
		if (!hDC_)
		{
			throw SILVER_EXCEPTION_CRITICAL("Unable to get device context.");
		}
	}

	void Window_win32::set_pixelFormatDescriptor_()
	{
		PIXELFORMATDESCRIPTOR pfd = {};
		pfd.nSize = sizeof(PIXELFORMATDESCRIPTOR);
		pfd.nVersion = 1;
		pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
		pfd.iPixelType = PFD_TYPE_RGBA;
		pfd.cColorBits = settings_.colorBit;
		pfd.cDepthBits = settings_.depthBit;
		pfd.cStencilBits = settings_.stencilBits;
		pfd.cAuxBuffers = settings_.auxBuffers;
		pfd.iLayerType = PFD_MAIN_PLANE;

		pixelFormat_ = ChoosePixelFormat(hDC_, &pfd);
		if (!pixelFormat_)
		{
			throw SILVER_EXCEPTION_CRITICAL("Unable to choose pixel format.");
		}
		else
		{
			if (!SetPixelFormat(hDC_, pixelFormat_, &pfd))
			{
				throw SILVER_EXCEPTION_CRITICAL("Unable to set pixel format.");
			}
		}
		context_.create(static_cast<void*>(hDC_));
	}

	void Window_win32::create_renderingContext_()
	{
		context_.create(static_cast<void*>(hDC_));
		hRC_ = static_cast<HGLRC> (context_.renderingContext());
	}

	void Window_win32::resizeEvent_handler_(const unsigned int width, const unsigned int height) noexcept
	{
		settings_.size = { width, height };

		auto e = std::make_unique<event::WindowResizeEvent>(settings_.size);
		resize_callback_(std::move(e));
	}
	
	void Window_win32::focus_handler_(const bool state) noexcept
	{
		settings_.focus = state;
		auto e = std::make_unique<event::WindowFocusEvent>(state);
		focus_callback_(std::move(e));
	}

	void Window_win32::close_handler_() const noexcept
	{
		auto e = std::make_unique<event::WindowCloseEvent>();
		close_callback_(std::move(e));
	}

	void Window_win32::create_handler_() const noexcept
	{
		auto e = std::make_unique<event::WindowCreateEvent>();
		create_callback_(std::move(e));
	}

	void Window_win32::destroy_handler_() const noexcept
	{
		auto e = std::make_unique<event::WindowDestroyEvent>();
		destroy_callback_(std::move(e));
	}

	void Window_win32::show_handler_(const bool state) noexcept
	{
		settings_.show = state;
		auto e = std::make_unique<event::WindowShowEvent>(state);
		show_callback_(std::move(e));
	}

	void Window_win32::keyboardEvent_handler_(UINT msg, WPARAM wparam, LPARAM lparam) const noexcept
	{
		auto position = mouse_position();
		auto code = KeyCodeTranslator_win32::translate(static_cast<unsigned int>(wparam));

		if (GetKeyState(VK_MENU) & 0x8000)
		{
			code |= KeyModifier::KEY_ALT;
		}
		if (GetKeyState(VK_CONTROL) & 0x8000)
		{
			code |= KeyModifier::KEY_CTRL;
		}
		if (GetKeyState(VK_SHIFT) & 0x8000)
		{
			code |= KeyModifier::KEY_SHIFT;
		}

		bool wasDown = (1 << 30) & (lparam);
		if (msg == WM_KEYDOWN || msg == WM_SYSKEYDOWN)
		{
			auto e = std::make_unique<event::KeyboardPressedEvent>(code, position, wasDown);
			keyboard_callback_(std::move(e));
		}
		else
		{
			auto e = std::make_unique<event::KeyboardReleasedEvent>(code, position, wasDown);
			keyboard_callback_(std::move(e));
		}
	}

	void Window_win32::mouseEvent_handler_(UINT msg, WPARAM wparam, LPARAM lparam) const noexcept
	{
		auto position = mouse_position();

		MouseCode code = [] (UINT msg)
		{
			switch (msg)
			{
				case WM_LBUTTONDOWN:
				case WM_LBUTTONUP:
					return MouseCode::MOUSE_LEFT;
				case WM_RBUTTONDOWN:
				case WM_RBUTTONUP:
					return MouseCode::MOUSE_RIGHT;
				case WM_MBUTTONDOWN:
				case WM_MBUTTONUP:
					return MouseCode::MOUSE_MIDDLE;
				case WM_MOUSEWHEEL:
					return MouseCode::MOUSE_WHEEL;
				default:
					return MouseCode::MOUSE_NO_CODE;
			}
		}(msg);

		if (GetKeyState(VK_MENU) & 0x8000)
		{
			code |= KeyModifier::KEY_ALT;
		}
		if (GetKeyState(VK_CONTROL) & 0x8000)
		{
			code |= KeyModifier::KEY_CTRL;
		}
		if (GetKeyState(VK_SHIFT) & 0x8000)
		{
			code |= KeyModifier::KEY_SHIFT;
		}

		if (msg == WM_MOUSEMOVE)
		{
			auto e = std::make_unique<event::MouseMovedEvent>(code, position);
			mouse_callback_(std::move(e));
		}
		else if (msg == WM_MOUSEWHEEL)
		{
			auto value = GET_WHEEL_DELTA_WPARAM(wparam) / 120;
			auto e = std::make_unique<event::MouseWheelEvent>(code, position, static_cast<int>(value));
			mouse_callback_(std::move(e));
		}
		else if (msg == WM_LBUTTONDOWN || msg == WM_RBUTTONDOWN || msg == WM_MBUTTONDOWN)
		{
			auto e = std::make_unique<event::MousePressedEvent>(code, position);
			mouse_callback_(std::move(e));
		}
		else
		{
			auto e = std::make_unique<event::MouseReleasedEvent>(code, position);
			mouse_callback_(std::move(e));
		}
	}

	LRESULT CALLBACK Window_win32::windowProc_callback(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam)
	{
		auto window = get_window(hwnd);

		switch (msg)
		{
			case WM_CREATE:
			{
				window->create_handler_();
				break;
			}
			case WM_SIZE:
			{
				window->resizeEvent_handler_(LOWORD(lparam), HIWORD(lparam));
				break;
			}
			case WM_SETFOCUS:
			{
				window->focus_handler_(true);
				break;
			}
			case WM_KILLFOCUS:
			{
				window->focus_handler_(false);
				break;
			}

			case WM_CLOSE:
			{
				window->close_handler_();
				break;
			}
			case WM_DESTROY:
			{
				window->destroy_handler_();
				break;
			}
			case WM_SHOWWINDOW:
			{
				window->show_handler_(wparam);
				break;
			}
			case WM_KEYDOWN:
			case WM_KEYUP:
			case WM_SYSKEYDOWN:
			case WM_SYSKEYUP:
			{
				window->keyboardEvent_handler_(msg, wparam, lparam);
				break;
			}
			case WM_LBUTTONDOWN:
			case WM_LBUTTONUP:
			case WM_RBUTTONDOWN:
			case WM_RBUTTONUP:
			case WM_MBUTTONDOWN:
			case WM_MBUTTONUP:
			case WM_MOUSEWHEEL:
			case WM_MOUSEMOVE:
			{
				window->mouseEvent_handler_(msg, wparam, lparam);
				break;
			}
		}
		return DefWindowProc(hwnd, msg, wparam, lparam);
	}
}