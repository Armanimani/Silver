#include "event\keyboard\KeyboardReleasedEvent.hpp"

namespace silver::core::event
{
	KeyboardReleasedEvent::KeyboardReleasedEvent(const KeyCode key, const vec2ui pos, const bool wasDown) : KeyboardEvent(key, KeyboardEvent::State::RELEASED, pos, wasDown) {}
}