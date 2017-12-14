#pragma once

#include "event\mouse\MouseEvent.hpp"

namespace silver::core::event
{
	class MouseReleasedEvent : public MouseEvent
	{
	public:
		MouseReleasedEvent(const MouseCode key, const vec2ui pos);
	};
}