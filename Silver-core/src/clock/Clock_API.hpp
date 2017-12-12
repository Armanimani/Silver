#pragma once

namespace silver::core
{
	class Clock_API
	{
	public:
		virtual ~Clock_API() {};

		virtual void reset() noexcept = 0;
		virtual float time() noexcept = 0;
	};
}