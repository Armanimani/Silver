#pragma once

#include "event\keyboard\KeyboardEvent.hpp"

namespace silver::core::event
{
	class KeyboardPressedEvent : public KeyboardEvent
	{
	public:
		KeyboardPressedEvent(const KeyCode key, const vec2ui pos, const bool wasDown);
	};
}