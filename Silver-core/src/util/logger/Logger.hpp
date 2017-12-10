#pragma once

#include "util\logger\platform\Logger_win32.hpp"

namespace silver::core
{
	#ifdef _WIN32
		using Logger = impl::Logger_win32;
	#endif
}