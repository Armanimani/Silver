#include "event\window\WindowFocusEvent.hpp"

#include <memory>

namespace silver::core::event
{
	WindowFocusEvent::WindowFocusEvent(const bool state) : WindowEvent(State::FOCUS), state_(std::move(state)) {}
	
	bool WindowFocusEvent::state() const noexcept
	{
		return state_;
	}
}