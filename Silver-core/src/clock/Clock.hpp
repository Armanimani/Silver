#pragma once

#ifdef _WIN32
	#include "platform\windows\Clock_win32.hpp"
	using Clock = silver::core::Clock_win32;
#endif