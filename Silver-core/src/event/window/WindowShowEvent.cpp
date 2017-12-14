#include "event\window\WindowShowEvent.hpp"

#include <memory>

namespace silver::core::event
{
	WindowShowEvent::WindowShowEvent(const bool state) : WindowEvent(State::SHOW), state_(std::move(state)) {}

	bool WindowShowEvent::state() const noexcept
	{
		return state_;
	}
}