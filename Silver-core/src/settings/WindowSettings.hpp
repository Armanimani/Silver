#pragma once

#include <string>

namespace silver::core
{
	struct WindowSettings
	{
		std::string name;
		unsigned int width { 800 };
		unsigned int height { 600 };
		bool vSync = false;
		bool fullScreen = false;
	};
}