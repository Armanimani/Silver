#pragma once

#include "event\mouse\MouseEvent.hpp"

namespace silver::core::event
{
	class MouseWheelEvent : public MouseEvent
	{
	public:
		MouseWheelEvent(const MouseCode key, const vec2ui pos, const int32 value);

		int32 value() const noexcept;

	protected:
		const int32 value_;
	};
}