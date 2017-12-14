#include "event\mouse\MouseMovedEvent.hpp"

namespace silver::core::event
{
	MouseMovedEvent::MouseMovedEvent(const MouseCode key, const vec2ui pos) : MouseEvent(key, State::MOVED, pos) {}
}