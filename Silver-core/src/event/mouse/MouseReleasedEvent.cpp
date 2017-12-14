#include "event\mouse\MouseReleasedEvent.hpp"

namespace silver::core::event
{
	MouseReleasedEvent::MouseReleasedEvent(const MouseCode key, const vec2ui pos) : MouseEvent(key, State::RELEASED, pos) {}
}