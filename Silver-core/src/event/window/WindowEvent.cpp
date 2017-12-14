#include "event\window\WindowEvent.hpp"

#include <memory>

namespace silver::core::event
{
	WindowEvent::WindowEvent(const State state) : Event_base(Type::WINDOW), state_(std::move(state)) {}

	WindowEvent::State WindowEvent::state() const noexcept
	{
		return state_;
	}
}