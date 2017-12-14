#pragma once

#include <memory>

#include "settings\WindowSettings.hpp"
#include "graphic\system\Context.hpp"
#include "event\events.hpp"
#include "math\math.hpp"

namespace silver::core
{
	class Window_API
	{
	public:
		Window_API(const WindowSettings& settings) : settings_(std::move(settings)) {}
		virtual ~Window_API() {}

		virtual void create() = 0;
		virtual void show(const bool state = true) = 0;
		virtual void update() = 0;
		virtual void focus(const bool state = true) noexcept = 0;

		virtual vec2ui mouse_position() const noexcept = 0;

		unsigned int width() const noexcept;
		unsigned int height() const noexcept;
		std::string title() const noexcept;

		virtual void set_width(const unsigned int width) noexcept = 0;
		virtual void set_height(const unsigned int height) noexcept = 0;
		virtual void set_size(const vec2ui size) noexcept = 0;
		virtual void set_title(const std::string& title) noexcept = 0;


		bool is_focus() const noexcept;
		bool is_fullScreen() const noexcept;
		bool is_shown() const noexcept;

	protected:
		WindowSettings settings_;
		graphic::Context context_;

		void resize_callback_(std::unique_ptr<event::WindowResizeEvent>&& e) const noexcept;
		void focus_callback_(std::unique_ptr<event::WindowFocusEvent>&& e) const noexcept;
		void close_callback_(std::unique_ptr<event::WindowCloseEvent>&& e) const noexcept;
		void create_callback_(std::unique_ptr<event::WindowCreateEvent>&& e) const noexcept;
		void destroy_callback_(std::unique_ptr<event::WindowDestroyEvent>&& e) const noexcept;
		void show_callback_(std::unique_ptr<event::WindowShowEvent>&& e) const noexcept;

		void keyboard_callback_(std::unique_ptr<event::KeyboardEvent>&& e) const noexcept;
		void mouse_callback_(std::unique_ptr<event::MouseEvent>&& e) const noexcept;
	};
}