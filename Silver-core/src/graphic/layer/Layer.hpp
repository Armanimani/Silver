#pragma once

#include "event\events.hpp"

namespace silver::core::graphic
{
	class Layer
	{
	public:
		void set_renderable(const bool state = true) noexcept;
		bool renderable() const noexcept;

		void set_active(const bool state = true) noexcept;
		bool active() const noexcept;

		void set_handle(const unsigned int handle) noexcept;
		unsigned int handle() const noexcept;
		
		virtual void on_init() noexcept {}
		virtual void on_update(const float dt_s) noexcept {}
		virtual void on_second_update() noexcept {}
		virtual void on_render() noexcept {}

		virtual void on_keyboard_event(std::unique_ptr<event::KeyboardEvent>&& e) {}
		virtual void on_mouse_event(std::unique_ptr<event::MouseEvent>&& e) {}
		virtual void on_window_create() {}
		virtual void on_window_close() {}
		virtual void on_window_destroy() {}
		virtual void on_window_resize(const vec2ui size) {}
		virtual void on_window_focus(const bool state) noexcept {};
		virtual void on_window_show(const bool state) {}

	protected:
		unsigned int handle_ {};
		bool renderable_ { true };
		bool active_ { true };
	};
}