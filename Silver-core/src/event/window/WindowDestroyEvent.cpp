#include "event\window\WindowDestroyEvent.hpp"

#include <memory>

namespace silver::core::event
{
	WindowDestroyEvent::WindowDestroyEvent() : WindowEvent(State::DESTROY) {}
}