#pragma once

#include "event\Event.hpp"

namespace silver::core::event
{
	class KeyboardEvent : Event
	{
	public:
		enum struct State
		{
			pressed,
			released,
		};

		enum class Modifiers
		{
			alt = 1 << 0,
			ctrl = 1 << 1,
			shift = 1 << 2,
		};

		State get_state() const noexcept;
		Modifiers get_modifiers() const noexcept;
		
		bool is_pressed() const noexcept;
		bool is_released() const noexcept;
		bool is_altDown() const noexcept;
		bool is_ctrlDown() const noexcept;
		bool is_shiftDown() const noexcept;

	protected:
		KeyboardEvent(const int keyCode, const State state);

		int keyCode_;
		State state_;
		Modifiers modifiers_;
	};
}