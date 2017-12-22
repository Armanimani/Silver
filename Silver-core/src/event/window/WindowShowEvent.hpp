#pragma once

#include "event\window\WindowEvent.hpp"
#include "common.hpp"

namespace silver::core::event
{
	class WindowShowEvent : public WindowEvent
	{
	public:
		WindowShowEvent(const bool state_);

		bool state() const noexcept;

	protected:
		bool state_;
	};
}
