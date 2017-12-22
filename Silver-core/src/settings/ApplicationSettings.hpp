#pragma once

#include "graphic\context\Context.hpp"

namespace silver::core
{
	struct ApplicationSettings
	{
		float updateFrequency = 0.0f;
		graphic::RenderingContext_API renderingContext = graphic::RenderingContext_API::OpenGL;
	};
}