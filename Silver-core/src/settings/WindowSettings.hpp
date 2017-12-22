#pragma once

#include <string>

#include "common.hpp"

namespace silver::core
{
	struct WindowSettings
	{
		std::string title { "silver engine" };
		vec2ui size { 800, 600 };
		bool vSync { false };
		bool fullScreen { false };
		bool focus { false };
		bool show { false };

		bool mouseShow { true };
		bool mouseLock { false };

		uint colorBit { 32 };
		uint depthBit { 24 };
		uint stencilBits { 8 };
		uint auxBuffers { 0 };
	};
}