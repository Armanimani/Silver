#pragma once

#include "graphic\context\RenderingContext.hpp"

namespace silver::core
{
	struct ApplicationSettings
	{
		float updateFrequency = 0.0f;
		graphic::RenderingContext renderingContext = graphic::RenderingContext::OpenGL;
	};
}