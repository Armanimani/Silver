#include "platform\windows\Clock_win32.hpp"

namespace silver::core
{
	Clock_win32::Clock_win32()
	{
		reset();
	}

	void Clock_win32::reset() noexcept
	{
		QueryPerformanceFrequency(&timeFrequency_);
		QueryPerformanceCounter(&startingTime_);
	}

	float Clock_win32::time() noexcept
	{
		LARGE_INTEGER newTime;
		QueryPerformanceCounter(&newTime);
		return static_cast<float>(newTime.QuadPart - startingTime_.QuadPart) / (timeFrequency_.QuadPart);
	}
}