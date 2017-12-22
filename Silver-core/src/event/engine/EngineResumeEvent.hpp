#pragma once

#include "event/engine/EngineEvent.hpp"

namespace silver::core::event
{
	class EngineResumeEvent : public EngineEvent
	{
	public:
		EngineResumeEvent() : EngineEvent(State::RESUME) {}
	};
}