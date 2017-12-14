#include "event\window\WindowResizeEvent.hpp"

#include <memory>

namespace silver::core::event
{
	WindowResizeEvent::WindowResizeEvent(const vec2ui size) : WindowEvent(State::RESIZE), size_(std::move(size)) {}

	vec2ui WindowResizeEvent::size() const noexcept
	{
		return size_;
	}

	unsigned int WindowResizeEvent::width() const noexcept
	{
		return size_.x;
	}

	unsigned int WindowResizeEvent::height()const noexcept
	{
		return size_.y;
	}
}