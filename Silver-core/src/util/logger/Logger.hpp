#pragma once

#ifdef _WIN32
	#include "platform\windows\Logger_win32.hpp"
	using Logger = silver::core::impl::Logger_win32;
#endif
