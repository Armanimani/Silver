#pragma once

#include <memory>

#include "settings\WindowSettings.hpp"
#include "graphic\context\Context.hpp"
#include "event\events.hpp"
#include "common.hpp"

namespace silver::core
{
	class Window_API
	{
	public:
		Window_API(const WindowSettings& settings) : settings_(std::move(settings)) {}
		virtual ~Window_API() {}

		virtual void create() = 0;
		virtual void show(const bool state = true) = 0;
		virtual void update() const noexcept= 0;
		virtual void clear() const noexcept= 0;
		virtual void focus(const bool state = true) noexcept = 0;

		virtual vec2ui mouse_position() const noexcept = 0;
		virtual void set_mouse_position(const vec2ui& pos) const noexcept = 0;
		virtual void lock_mouse(const bool state = true) noexcept = 0;
		virtual void show_mouse(const bool state = true) noexcept = 0;
		bool is_mouse_locked() const noexcept;
		bool is_mouse_visible() const noexcept;

		virtual vec2ui screen_resolution() const noexcept = 0;
		virtual uint screen_resolutionX() const noexcept = 0;
		virtual uint screen_resolutionY() const noexcept = 0;

		uint width() const noexcept;
		uint height() const noexcept;
		vec2ui size() const noexcept;
		std::string title() const noexcept;

		virtual void set_width(const uint width) noexcept = 0;
		virtual void set_height(const uint height) noexcept = 0;
		virtual void set_size(const vec2ui size) noexcept = 0;
		virtual void set_title(const std::string& title) noexcept = 0;

		bool is_focus() const noexcept;
		bool is_fullScreen() const noexcept;
		bool is_shown() const noexcept;

	protected:
		WindowSettings settings_;

		void window_callback_(std::unique_ptr<event::WindowEvent>&& e) const noexcept;
		void keyboard_callback_(std::unique_ptr<event::KeyboardEvent>&& e) const noexcept;
		void mouse_callback_(std::unique_ptr<event::MouseEvent>&& e) const noexcept;
	};
}