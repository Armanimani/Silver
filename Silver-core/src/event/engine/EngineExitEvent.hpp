#pragma once

#include "event/engine/EngineEvent.hpp"

namespace silver::core::event
{
	class EngineExitEvent : public EngineEvent
	{
	public:
		EngineExitEvent() : EngineEvent(State::EXIT) {}
	};
}