#include "event\mouse\MouseEvent.hpp"

#include <memory>

namespace silver::core::event
{
	MouseEvent::MouseEvent(const MouseCode key, const State state, const vec2ui pos) : Event_base(Event_base::Type::MOUSE), key_(std::move(key)), state_(std::move(state)), pos_(std::move(pos)) {}

	MouseEvent::State MouseEvent::state() const noexcept
	{
		return state_;
	}

	MouseCode MouseEvent::key() const noexcept
	{
		return key_;
	}

	bool MouseEvent::pressed() const noexcept
	{
		return (state_ == State::PRESSED);
	}

	bool MouseEvent::released() const noexcept
	{
		return (state_ == State::RELEASED);
	}

	uint MouseEvent::x() const noexcept
	{
		return pos_.y;
	}

	uint MouseEvent::y() const noexcept
	{
		return pos_.x;
	}

	vec2ui MouseEvent::position() const noexcept
	{
		return pos_;
	}
	
	bool MouseEvent::alt() const noexcept
	{
		return toBool((key_ & KeyModifier::KEY_MASK) & KeyModifier::KEY_ALT);
	}

	bool MouseEvent::ctrl() const noexcept
	{
		return toBool((key_ & KeyModifier::KEY_MASK) & KeyModifier::KEY_CTRL);
	}

	bool MouseEvent::shift() const noexcept
	{
		return toBool((key_ & KeyModifier::KEY_MASK) & KeyModifier::KEY_SHIFT);
	}

	bool MouseEvent::win() const noexcept
	{
		return toBool((key_ & KeyModifier::KEY_MASK) & KeyModifier::KEY_WIN);
	}
}