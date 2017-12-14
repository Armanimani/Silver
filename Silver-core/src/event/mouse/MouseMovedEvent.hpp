#pragma once

#include "event\mouse\MouseEvent.hpp"

namespace silver::core::event
{
	class MouseMovedEvent : public MouseEvent
	{
	public:
		MouseMovedEvent(const MouseCode key, const vec2ui pos);
	};
}