#pragma once

#include "event/engine/EngineEvent.hpp"

namespace silver::core::event
{
	class EnginePauseEvent : public EngineEvent
	{
	public:
		EnginePauseEvent() : EngineEvent(State::PAUSE) {}
	};
}