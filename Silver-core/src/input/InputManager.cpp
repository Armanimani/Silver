#include "input\InputManager.hpp"

#include "util\logger\Logger.hpp"

namespace silver::core
{
	std::unique_ptr<InputManager> InputManager::s_instance_;
	InputManager& InputManager::instance()
	{
		if (!s_instance_)
		{
			s_instance_ = std::make_unique<InputManager>();
			s_instance_->clear();
		}
		return *s_instance_;
	}

	InputManager::InputManager() {}

	void InputManager::update() noexcept
	{
		lastKeyState_ = keyState_;
		lastMouseState_ = mouseState_;
	}

	void InputManager::clear() noexcept
	{
		keyState_.fill(false);
		lastKeyState_.fill(false);

		mouseState_.fill(false);
		lastMouseState_.fill(false);
	}

	void InputManager::catch_mouseEvent(std::unique_ptr<event::MouseEvent>&& e) noexcept
	{
		s_instance_->mousePosition_ = e->position();
		if (e->state() != event::MouseEvent::State::MOVED)
		{
			s_instance_->keyState_[static_cast<unsigned int>(KeyCode::KEY_ALT)] = e->alt();
			s_instance_->keyState_[static_cast<unsigned int>(KeyCode::KEY_CTRL)] = e->ctrl();
			s_instance_->keyState_[static_cast<unsigned int>(KeyCode::KEY_SHIFT)] = e->shift();
			s_instance_->keyState_[static_cast<unsigned int>(KeyCode::KEY_WIN)] = e->win();
			if (e->state() == event::MouseEvent::State::WHEEL)
			{
				auto p = static_cast<event::MouseWheelEvent*>(e.get());
				s_instance_->mouseWheelValue_ = p->value();
			} 
			else if (e->state() == event::MouseEvent::State::PRESSED)
			{
				s_instance_->keyState_[static_cast<unsigned int>(e->key())] = true;
			}
			else if (e->state() == event::MouseEvent::State::RELEASED)
			{
				s_instance_->keyState_[static_cast<unsigned int>(e->key())] = false;
			}
		}
		s_instance_->eventCallback_(std::move(e));
	}

	void InputManager::catch_keyboardEvent(std::unique_ptr<event::KeyboardEvent>&& e) noexcept
	{
		s_instance_->mousePosition_ = e->position();

		s_instance_->keyState_[static_cast<unsigned int>(KeyCode::KEY_ALT)] = e->alt();
		s_instance_->keyState_[static_cast<unsigned int>(KeyCode::KEY_CTRL)] = e->ctrl();
		s_instance_->keyState_[static_cast<unsigned int>(KeyCode::KEY_SHIFT)] = e->shift();
		s_instance_->keyState_[static_cast<unsigned int>(KeyCode::KEY_WIN)] = e->win();

		if (e->state() == event::KeyboardEvent::State::PRESSED)
		{
			s_instance_->keyState_[static_cast<unsigned int>(e->key())] = true;
		}
		else if (e->state() == event::KeyboardEvent::State::RELEASED)
		{
			s_instance_->keyState_[static_cast<unsigned int>(e->key())] = false;
		}
		s_instance_->eventCallback_(std::move(e));
	}

	void InputManager::catch_windowEvent(std::unique_ptr<event::WindowEvent>&& e) noexcept
	{
		s_instance_->eventCallback_(std::move(e));
	}

	void InputManager::set_event_callback(EventCallback_t func)
	{
		eventCallback_ = func;
	}

	bool InputManager::is_key_pressed(const KeyCode code) const noexcept
	{
		return keyState_[static_cast<unsigned int>(code)];
	}

	bool InputManager::is_key_released(const KeyCode code) const noexcept
	{
		return (lastKeyState_[static_cast<unsigned int>(code)] && !keyState_[static_cast<unsigned int>(code)]);
	}

	bool InputManager::is_key_held(const KeyCode code) const noexcept
	{
		return (lastKeyState_[static_cast<unsigned int>(code)] && keyState_[static_cast<unsigned int>(code)]);
	}

	bool InputManager::was_key_pressed(const KeyCode code) const noexcept
	{
		return lastKeyState_[static_cast<unsigned int>(code)];
	}

	bool InputManager::is_mouse_pressed(const MouseCode code) const noexcept
	{
		return mouseState_[static_cast<unsigned int>(code)];
	}

	bool InputManager::is_mouse_released(const MouseCode code) const noexcept
	{
		return (lastMouseState_[static_cast<unsigned int>(code)] && !mouseState_[static_cast<unsigned int>(code)]);
	}

	bool InputManager::is_mouse_held(const MouseCode code) const noexcept
	{
		return (lastMouseState_[static_cast<unsigned int>(code)] && mouseState_[static_cast<unsigned int>(code)]);
	}

	bool InputManager::was_mouse_pressed(const MouseCode code) const noexcept
	{
		return lastMouseState_[static_cast<unsigned int>(code)];
	}

	vec2ui InputManager::mouse_position() const noexcept
	{
		return mousePosition_;
	}

	unsigned int InputManager::mouse_wheel() const noexcept
	{
		return mouseWheelValue_;
	}
}