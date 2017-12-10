#pragma once

namespace silver::core
{
	class Clock_interface
	{
	public:
		virtual void reset() noexcept = 0;
		virtual float time() noexcept = 0;
	};
}