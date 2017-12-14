#pragma once

#include "event\window\WindowEvent.hpp"
#include "math\math.hpp"

namespace silver::core::event
{
	class WindowCloseEvent : public WindowEvent
	{
	public:
		WindowCloseEvent();
	};
}