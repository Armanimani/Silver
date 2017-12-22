#pragma once

#include "event\window\WindowEvent.hpp"
#include "common.hpp"

namespace silver::core::event
{
	class WindowDestroyEvent : public WindowEvent
	{
	public:
		WindowDestroyEvent();
	};
}