#pragma once

#include "event\keyboard\KeyboardEvent.hpp"

namespace silver::core::event
{
	class KeyboardReleasedEvent : public KeyboardEvent
	{
	public:
		KeyboardReleasedEvent(const KeyCode key, const vec2ui pos, const bool wasDown);
	};
}