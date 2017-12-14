#pragma once

#include "event\Event_base.hpp"
#include "input\MouseCode.hpp"
#include "math\math.hpp"

namespace silver::core::event
{
	class MouseEvent : public Event_base
	{
	public:
		enum struct State
		{
			PRESSED,
			RELEASED,
			WHEEL,
			MOVED,
		};

		MouseEvent(const MouseCode key, const State state, const vec2ui pos);

		State state() const noexcept;
		MouseCode key() const noexcept;

		bool pressed() const noexcept;
		bool released() const noexcept;

		unsigned int x() const noexcept;
		unsigned int y() const noexcept;
		vec2ui position() const noexcept;

		bool alt() const noexcept;
		bool ctrl() const noexcept;
		bool shift() const noexcept;
		bool win() const noexcept;

	protected:
		const MouseCode key_;
		const State state_;
		const vec2ui pos_;
	};
}