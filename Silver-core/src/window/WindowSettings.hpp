#pragma once

namespace silver::core
{
	struct WindowSettings
	{
		unsigned int width { 800 };
		unsigned int height { 600 };
		bool vSync = false;
		bool fullScreen = false;
	};
}