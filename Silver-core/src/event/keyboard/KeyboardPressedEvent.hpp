#pragma once

#include "event\keyboard\KeyboardEvent.hpp"

namespace silver::core::event
{
	class KeyboardPressedEvent : KeyboardEvent
	{
	public:
		using Modifiers = KeyboardEvent::Modifiers;
		KeyboardPressedEvent(const int keyCode, const int repeat, const Modifiers modifiers);

	protected:
	};
}