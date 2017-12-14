#pragma once

#include <string>
#include "math\math.hpp"

namespace silver::core
{
	struct WindowSettings
	{
		std::string title { "silver engine" };
		vec2ui size { 800, 600 };
		bool vSync = false;
		bool fullScreen = false;
		bool focus = false;
		bool show = false;

		unsigned int colorBit { 32 };
		unsigned int depthBit { 24 };
		unsigned int stencilBits { 8 };
		unsigned int auxBuffers { 0 };
	};
}