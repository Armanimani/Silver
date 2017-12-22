#pragma once

#include "event/engine/EngineEvent.hpp"

namespace silver::core::event
{
	class EngineStopEvent : public EngineEvent
	{
	public:
		EngineStopEvent() : EngineEvent(State::STOP) {}
	};
}