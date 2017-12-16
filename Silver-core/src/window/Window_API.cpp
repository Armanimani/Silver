#include "window\Window_API.hpp"

#include "util\logger\Logger.hpp"
#include "util\translator\Translator.hpp"
#include "event\events.hpp"
#include "input\InputManager.hpp"

namespace silver::core
{
	bool Window_API::is_mouse_locked() const noexcept
	{
		return settings_.mouseLock;
	}

	bool Window_API::is_mouse_visible() const noexcept
	{
		return settings_.mouseShow;
	}

	unsigned int Window_API::width() const noexcept
	{
		return settings_.size.x;
	}

	unsigned int Window_API::height() const noexcept
	{
		return settings_.size.y;
	}

	vec2ui Window_API::size() const noexcept
	{
		return settings_.size;
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

	void Window_API::window_callback_(std::unique_ptr<event::WindowEvent>&& e) const noexcept
	{
		InputManager::instance().catch_windowEvent(std::move(e));
	}

	void Window_API::keyboard_callback_(std::unique_ptr<event::KeyboardEvent>&& e) const noexcept
	{
		InputManager::instance().catch_keyboardEvent(std::move(e));
	}

	void Window_API::mouse_callback_(std::unique_ptr<event::MouseEvent>&& e) const noexcept
	{
		InputManager::instance().catch_mouseEvent(std::move(e));
	}
}