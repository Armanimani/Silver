#pragma once

#include "event\window\WindowEvent.hpp"
#include "math\math.hpp"

namespace silver::core::event
{
	class WindowFocusEvent : public WindowEvent
	{
	public:
		WindowFocusEvent(const bool state_);

		bool state() const noexcept;

	protected:
		bool state_;
	};
}