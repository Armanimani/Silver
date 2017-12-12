#pragma once

#include <string>

namespace silver::core
{
	struct WindowSettings
	{
		std::string title { "silver engine" };
		unsigned int width { 800 };
		unsigned int height { 600 };
		bool vSync = false;
		bool fullScreen = false;
		bool focus = true;

		unsigned int colorBit { 32 };
		unsigned int depthBit { 24 };
		unsigned int stencilBits { 8 };
		unsigned int auxBuffers { 0 };
	};
}