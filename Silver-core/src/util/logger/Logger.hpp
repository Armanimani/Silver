#pragma once

#ifdef _WIN32
	#include "platform\windows\Logger_win32.hpp"
	namespace silver::core
	{
		using Logger = impl::Logger_win32;
	}
#endif