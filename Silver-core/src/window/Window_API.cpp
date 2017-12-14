#include "window\Window_API.hpp"

#include "util\logger\Logger.hpp"
#include "util\translator\Translator.hpp"
#include "event\events.hpp"

namespace silver::core
{
	unsigned int Window_API::width() const noexcept
	{
		return settings_.size.x;
	}

	unsigned int Window_API::height() const noexcept
	{
		return settings_.size.y;
	}

	std::string Window_API::title() const noexcept
	{
		return settings_.title;
	}

	bool Window_API::is_focus() const noexcept
	{
		return settings_.focus;
	}

	bool Window_API::is_fullScreen() const noexcept
	{
		return settings_.fullScreen;
	}

	bool Window_API::is_shown() const noexcept
	{
		return settings_.show;
	}

	void Window_API::resize_callback_(std::unique_ptr<event::WindowResizeEvent>&& e) const noexcept
	{
		Logger::instance().log(*e);
	}

	void Window_API::focus_callback_(std::unique_ptr<event::WindowFocusEvent>&& e) const noexcept
	{
		Logger::instance().log(*e);
	}

	void Window_API::close_callback_(std::unique_ptr<event::WindowCloseEvent>&& e) const noexcept
	{
		Logger::instance().log(*e);
	}

	void Window_API::create_callback_(std::unique_ptr<event::WindowCreateEvent>&& e) const noexcept
	{
		Logger::instance().log(*e);
	}

	void Window_API::destroy_callback_(std::unique_ptr<event::WindowDestroyEvent>&& e) const noexcept
	{
		Logger::instance().log(*e);
	}

	void Window_API::show_callback_(std::unique_ptr<event::WindowShowEvent>&& e) const noexcept
	{
		Logger::instance().log(*e);
	}

	void Window_API::keyboard_callback_(std::unique_ptr<event::KeyboardEvent>&& e) const noexcept
	{
		if (e->state() == event::KeyboardEvent::State::PRESSED)
		{
			auto p = static_cast<event::KeyboardPressedEvent*>(e.get());
			Logger::instance().log(*p);
		}
		else if (e->state() == event::KeyboardEvent::State::RELEASED)
		{
			auto p = static_cast<event::KeyboardReleasedEvent*>(e.get());
			Logger::instance().log(*p);
		}
	}

	void Window_API::mouse_callback_(std::unique_ptr<event::MouseEvent>&& e) const noexcept
	{
		if (e->state() == event::MouseEvent::State::MOVED)
		{
			auto p = static_cast<event::MouseMovedEvent*>(e.get());
			//Logger::instance().log(*p);
		}
		else if (e->state() == event::MouseEvent::State::PRESSED)
		{
			auto p = static_cast<event::MousePressedEvent*>(e.get());
			Logger::instance().log(*p);
		}
		else if (e->state() == event::MouseEvent::State::RELEASED)
		{
			auto p = static_cast<event::MouseReleasedEvent*>(e.get());
			Logger::instance().log(*p);
		}
		else if (e->state() == event::MouseEvent::State::WHEEL)
		{
			auto p = static_cast<event::MouseWheelEvent*>(e.get());
			Logger::instance().log(*p);
		}
	}
}