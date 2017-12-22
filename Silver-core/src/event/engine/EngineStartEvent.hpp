#pragma once

#include "event/engine/EngineEvent.hpp"

namespace silver::core::event
{
	class EngineStartEvent : public EngineEvent
	{
	public:
		EngineStartEvent() : EngineEvent(State::START) {}
	};
}