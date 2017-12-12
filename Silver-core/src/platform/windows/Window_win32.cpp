#include "platform\windows\Window_win32.hpp"

#include "util\logger\Logger.hpp"
#include "common.hpp"

namespace silver::core
{
	const char* WINDOW_CLASS_NAME = "silver-window";

	HINSTANCE Window_win32::s_hInstance_ = nullptr;
	std::map<HWND, Window_win32*> Window_win32::s_handles_;
	bool Window_win32::s_windowRegistered = false;

	Window_win32::Window_win32(const WindowSettings& settings) : Window_API(settings)
	{
	}
	
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
			SetFocus(hWnd_);
		}
		else
			ShowWindow(hWnd_, SW_HIDE);
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

	void Window_win32::set_width(const unsigned int value) noexcept
	{
		settings_.width = value;
		SetWindowPos(hWnd_, nullptr, 0, 0, value, height(), SWP_NOMOVE);
	}

	void Window_win32::set_height(const unsigned int value) noexcept
	{
		settings_.height = value;
		SetWindowPos(hWnd_, nullptr, 0, 0, width(), value, SWP_NOMOVE);
	}

	void Window_win32::set_title(const std::string& title) noexcept
	{
		settings_.title = title;
		SetWindowText(hWnd_, title.c_str());
	}

	void Window_win32::focus(const bool state) noexcept
	{
		settings_.focus = state;
		if (state)
			SetFocus(hWnd_);
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
		rect.right = settings_.width;
		rect.bottom = settings_.height;

		DWORD dwStyle = WS_CLIPCHILDREN | WS_CLIPSIBLINGS | WS_OVERLAPPEDWINDOW;
		DWORD dwExStyle = WS_EX_APPWINDOW | WS_EX_WINDOWEDGE;
		AdjustWindowRectEx(&rect, dwStyle, false, dwExStyle);

		int windowX = (GetSystemMetrics(SM_CXSCREEN) - settings_.width) / 2;
		int windowY = (GetSystemMetrics(SM_CYSCREEN) - settings_.height) / 2;
		hWnd_ = CreateWindowExA(dwExStyle, WINDOW_CLASS_NAME, settings_.title.c_str(), dwStyle, windowX, windowY, settings_.width, settings_.height, nullptr, nullptr, s_hInstance_, nullptr);
		
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

	void Window_win32::focus_callback_(bool state)
	{
		settings_.focus = state;
	}

	void Window_win32::resize_callback_(const unsigned int width, const unsigned int height)
	{
		settings_.width = width;
		settings_.height = height;
	}

	void Window_win32::close_callback_()
	{

	}

	LRESULT CALLBACK Window_win32::windowProc_callback(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam)
	{
		auto window = get_window(hwnd);

		switch (msg)
		{
			case WM_SIZE:
			{
				window->resize_callback_(LOWORD(lparam), HIWORD(lparam));
				break;
			}
			case WM_SETFOCUS:
			{
				window->focus_callback_(true);
				break;
			}
			case WM_KILLFOCUS:
			{
				window->focus_callback_(false);
				break;
			}

			case WM_CLOSE:
			{
				window->close_callback_();
				break;
			}
			case WM_DESTROY:
			{
				PostQuitMessage(0);
				break;
			}
			case WM_KEYDOWN:
			case WM_KEYUP:
			case WM_SYSKEYDOWN:
			case WM_SYSKEYUP:
			{
				//keyboard call back
				break;
			}
			case WM_LBUTTONDOWN:
			case WM_LBUTTONUP:
			case WM_RBUTTONDOWN:
			case WM_RBUTTONUP:
			case WM_MBUTTONDOWN:
			case WM_MBUTTONUP:
			{
				//mouse call back
				break;
			}
		}

		return DefWindowProc(hwnd, msg, wparam, lparam);
	}
}