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

		void set_width(const unsigned int width) noexcept override;
		void set_height(const unsigned int height) noexcept override;
		void set_title(const std::string& title) noexcept override;

		void focus(const bool state = true) noexcept override;


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

		void focus_callback_(bool state) override;
		void resize_callback_(const unsigned int width, const unsigned int height) override;
		void close_callback_() override;
	};
}