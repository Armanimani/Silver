#pragma once

#include "event\Event_base.hpp"

namespace silver::core::event
{
	class WindowEvent : public Event_base
	{
	public:
		enum class State
		{
			RESIZE,
			FOCUS,
			CLOSE,
			DESTROY,
			CREATE,
			SHOW,
		};

		WindowEvent(const State state);

		State state() const noexcept;

	protected:
		const State state_;
	};
}