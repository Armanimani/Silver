#pragma once

#include "event\Event_base.hpp"
#include "common.hpp"

namespace silver::core::event
{
	class EngineEvent : public Event_base
	{
	public:
		enum struct State
		{
			PAUSE,
			RESUME,
			START,
			STOP,
			EXIT,
		};

		EngineEvent(const State state) : Event_base(EngineEvent::Type::ENGINE), state_(std::move(state)) {}

		State state() const noexcept { return state_; }

	protected:
		const State state_;
	};
}