#pragma once

#include "event\window\WindowEvent.hpp"
#include "math\math.hpp"

namespace silver::core::event
{
	class WindowDestroyEvent : public WindowEvent
	{
	public:
		WindowDestroyEvent();
	};
}