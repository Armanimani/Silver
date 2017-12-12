#pragma once

#include "settings\WindowSettings.hpp"
#include "graphic\system\Context.hpp"

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

		unsigned int width() const noexcept;
		unsigned int height() const noexcept;
		std::string title() const noexcept;

		virtual void set_width(const unsigned int width) noexcept = 0;
		virtual void set_height(const unsigned int height) noexcept = 0;
		virtual void set_title(const std::string& title) noexcept = 0;

		virtual void focus(const bool state = true) noexcept = 0;
		bool is_focus() const noexcept;
		bool is_fullScreen() const noexcept;

	protected:
		WindowSettings settings_;
		graphic::Context context_;

		virtual void focus_callback_(bool state) {};
		virtual void resize_callback_(const unsigned int width, const unsigned int height) {};
		virtual void close_callback_() {};
	};
}