#include "event\keyboard\KeyboardPressedEvent.hpp"

namespace silver::core::event
{
	KeyboardPressedEvent::KeyboardPressedEvent(const int keyCode, const int repeat, const Modifiers modifiers) : KeyboardEvent(keyCode, KeyboardEvent::State::pressed)
	{

	}
}