#pragma once

#include <Windows.h>
#include <map>

#include "window\Window_API.hpp"

namespace silver::core
{
	class Window_win32 : public Window_API
	{
	public:
		Window_win32(const WindowSettings& settings);
		~Window_win32();
		
		void create() override;
		void show(const bool state = true) override;
		void update() override;
		void focus(const bool state = true) noexcept override;
		
		vec2ui mouse_position() const noexcept override;

		void set_width(const unsigned int width) noexcept override;
		void set_height(const unsigned int height) noexcept override;
		void set_size(const vec2ui size) noexcept override;
		void set_title(const std::string& title) noexcept override;

	private:
		static HINSTANCE s_hInstance_;
		static std::map<HWND, Window_win32*> s_handles_;
		static bool s_windowRegistered;

		static LRESULT CALLBACK windowProc_callback(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam);

		HWND hWnd_ {};
		HDC hDC_ {};
		HGLRC hRC_ {};
		unsigned int pixelFormat_ {};

		static Window_win32* get_window(const HWND& hwnd);
		static void get_applicationHandle_();
		static void register_windowClass_();

		void create_window_();
		void get_deviceContext_();
		void set_pixelFormatDescriptor_();
		void create_renderingContext_();

		void resizeEvent_handler_(const unsigned int width, const unsigned int height) noexcept;
		void focus_handler_(const bool state) noexcept;
		void close_handler_() const noexcept;
		void create_handler_() const noexcept;
		void destroy_handler_() const noexcept;
		void show_handler_(const bool state) noexcept;

		void keyboardEvent_handler_(UINT msg, WPARAM wparam, LPARAM lparam) const noexcept;
		void mouseEvent_handler_(UINT msg, WPARAM wparam, LPARAM lparam) const noexcept;
	};
}