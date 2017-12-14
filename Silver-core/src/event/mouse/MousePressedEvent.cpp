#include "event\mouse\MousePressedEvent.hpp"

namespace silver::core::event
{
	MousePressedEvent::MousePressedEvent(const MouseCode key, const vec2ui pos) : MouseEvent(key, State::PRESSED, pos) {}
}