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
		void set_mouse_position(const vec2ui& pos) const noexcept override;
		void lock_mouse(const bool state = true) noexcept override;
		void show_mouse(const bool state = true) noexcept override;

		vec2ui screen_resolution() const noexcept override;
		unsigned int screen_resolutionX() const noexcept override;
		unsigned int screen_resolutionY() const noexcept override;

		void set_width(const unsigned int width) noexcept override;
		void set_height(const unsigned int height) noexcept override;
		void set_size(const vec2ui size) noexcept override;
		void set_title(const std::string& title) noexcept override;

	private:
		static std::string s_windowClassName;
		static HINSTANCE s_hInstance_;
		static std::map<HWND, Window_win32*> s_handles_;
		static bool s_windowRegistered;

		std::unique_ptr<HANDLE> icon_;
		HWND hWnd_ {};
		HDC hDC_ {};
		HGLRC hRC_ {};
		unsigned int pixelFormat_ {};

		static Window_win32* get_window_(const HWND& hwnd);
		static void get_applicationHandle_();
		static void register_windowClass_();
		static LRESULT CALLBACK windowProc_callback(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam);

		void create_window_();
		void get_deviceContext_();
		void set_pixelFormatDescriptor_();
		void create_renderingContext_();

		void windowEvent_handler_(UINT msg, WPARAM wparam, LPARAM lparam) noexcept;
		void keyboardEvent_handler_(UINT msg, WPARAM wparam, LPARAM lparam) const noexcept;
		void mouseEvent_handler_(UINT msg, WPARAM wparam, LPARAM lparam) const noexcept;
	};
}