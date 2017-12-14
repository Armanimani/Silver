#pragma once

#include "event\window\WindowEvent.hpp"
#include "math\math.hpp"

namespace silver::core::event
{
	class WindowResizeEvent : public WindowEvent
	{
	public:
		WindowResizeEvent(const vec2ui size);

		vec2ui size() const noexcept;
		unsigned int width() const noexcept;
		unsigned int height() const noexcept;

	protected:
		vec2ui size_;
	};
}