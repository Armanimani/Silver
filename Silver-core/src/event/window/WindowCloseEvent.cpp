#include "event\window\WindowCloseEvent.hpp"

#include <memory>

namespace silver::core::event
{
	WindowCloseEvent::WindowCloseEvent() : WindowEvent(State::CLOSE) {}
}