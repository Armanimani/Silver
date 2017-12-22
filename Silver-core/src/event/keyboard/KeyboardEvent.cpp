#include "event\keyboard\KeyboardEvent.hpp"

#include <memory>

namespace silver::core::event
{
	KeyboardEvent::KeyboardEvent(const KeyCode key, const State state, const vec2ui pos, const bool wasDown) : Event_base(Event_base::Type::KEYBOARD), key_(std::move(key)), state_(std::move(state)), pos_(std::move(pos)), wasDown_(std::move(wasDown)) {}

	KeyboardEvent::State KeyboardEvent::state() const noexcept
	{
		return state_;
	}

	KeyCode KeyboardEvent::key() const noexcept
	{
		return key_ & KeyModifier::KEY_REMOVE_MASK;
	}

	bool KeyboardEvent::pressed() const noexcept
	{
		return (state_ == State::PRESSED);
	}

	bool KeyboardEvent::released() const noexcept
	{
		return (state_ == State::RELEASED);
	}

	uint KeyboardEvent::x() const noexcept
	{
		return pos_.y;
	}

	uint KeyboardEvent::y() const noexcept
	{
		return pos_.x;
	}

	vec2ui KeyboardEvent::position() const noexcept
	{
		return pos_;
	}


	bool KeyboardEvent::was_down() const noexcept
	{
		return wasDown_;
	}

	bool KeyboardEvent::alt() const noexcept
	{
		return toBool((key_ & KeyModifier::KEY_MASK) & KeyModifier::KEY_ALT);
	}

	bool KeyboardEvent::ctrl() const noexcept
	{
		return toBool((key_ & KeyModifier::KEY_MASK) & KeyModifier::KEY_CTRL);
	}

	bool KeyboardEvent::shift() const noexcept
	{
		return toBool((key_ & KeyModifier::KEY_MASK) & KeyModifier::KEY_SHIFT);
	}

	bool KeyboardEvent::win() const noexcept
	{
		return toBool((key_ & KeyModifier::KEY_MASK) & KeyModifier::KEY_WIN);
	}
}