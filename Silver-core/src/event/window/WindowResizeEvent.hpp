#pragma once

#include "event\window\WindowEvent.hpp"
#include "common.hpp"

namespace silver::core::event
{
	class WindowResizeEvent : public WindowEvent
	{
	public:
		WindowResizeEvent(const vec2ui size);

		vec2ui size() const noexcept;
		uint width() const noexcept;
		uint height() const noexcept;

	protected:
		vec2ui size_;
	};
}