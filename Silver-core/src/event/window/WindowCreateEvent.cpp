#include "event\window\WindowCreateEvent.hpp"

#include <memory>

namespace silver::core::event
{
	WindowCreateEvent::WindowCreateEvent() : WindowEvent(State::CREATE) {}
}