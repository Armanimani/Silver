#pragma once

#include "event\window\WindowEvent.hpp"
#include "common.hpp"

namespace silver::core::event
{
	class WindowCloseEvent : public WindowEvent
	{
	public:
		WindowCloseEvent();
	};
}