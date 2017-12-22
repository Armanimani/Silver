#pragma once

#ifdef _WIN32
	#include "platform\windows\FileReader_win32.hpp"

	namespace silver::core
	{
		using FileReader = FileReader_win32;
	}
#endif