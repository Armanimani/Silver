#pragma once

#ifdef _WIN32
	#include "platform\windows\Clock_win32.hpp"

	namespace silver::core
	{
		using Clock = Clock_win32;
	}
#endif
