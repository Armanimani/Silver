#pragma once

#include "event\mouse\MouseEvent.hpp"

namespace silver::core::event
{
	class MousePressedEvent : public MouseEvent
	{
	public:
		MousePressedEvent(const MouseCode key, const vec2ui pos);
	};
}