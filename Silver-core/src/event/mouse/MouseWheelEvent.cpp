#include "event\mouse\MouseWheelEvent.hpp"

namespace silver::core::event
{
	MouseWheelEvent::MouseWheelEvent(const MouseCode key, const vec2ui pos, const int32 value) : MouseEvent(key, State::WHEEL, pos), value_(std::move(value)) {}

	int32 MouseWheelEvent::value() const noexcept
	{
		return value_;
	}
}