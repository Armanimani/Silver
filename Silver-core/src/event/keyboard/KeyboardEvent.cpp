#include "event\keyboard\KeyboardEvent.hpp"

#include <memory>

namespace silver::core::event
{
	KeyboardEvent::KeyboardEvent(const int keyCode, const State state) : Event(Event::Type::keyboard), keyCode_(std::move(keyCode)), state_(std::move(state))
	{
	}

	KeyboardEvent::State KeyboardEvent::get_state() const noexcept
	{
		return state_;
	}

	KeyboardEvent::Modifiers KeyboardEvent::get_modifiers() const noexcept
	{
		return modifiers_;
	}

	bool KeyboardEvent::is_pressed() const noexcept
	{
		return (state_ == State::pressed);
	}

	bool KeyboardEvent::is_released() const noexcept
	{
		return (state_ == State::released);
	}

	bool KeyboardEvent::is_altDown() const noexcept
	{
		return (static_cast<int>(modifiers_) & static_cast<int>(Modifiers::alt));
	}

	bool KeyboardEvent::is_ctrlDown() const noexcept
	{
		return (static_cast<int>(modifiers_) & static_cast<int>(Modifiers::ctrl));
	}

	bool KeyboardEvent::is_shiftDown() const noexcept
	{
		return (static_cast<int>(modifiers_) & static_cast<int>(Modifiers::shift));
	}
}