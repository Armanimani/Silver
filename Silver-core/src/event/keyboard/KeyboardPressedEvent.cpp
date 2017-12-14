#include "event\keyboard\KeyboardPressedEvent.hpp"

namespace silver::core::event
{
	KeyboardPressedEvent::KeyboardPressedEvent(const KeyCode key, const vec2ui pos, const bool wasDown) : KeyboardEvent(key, KeyboardEvent::State::PRESSED, pos, wasDown) {}
}