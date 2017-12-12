#pragma once

#include <Windows.h>

#include "clock\Clock_API.hpp"

namespace silver::core
{
	class Clock_win32 : public Clock_API
	{
	public:
		Clock_win32();

		void reset() noexcept override;
		float time() noexcept override;

	private:
		LARGE_INTEGER timeFrequency_ {};
		LARGE_INTEGER startingTime_ {};
	};
}
