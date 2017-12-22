#pragma once

#include <vector>

#include "graphic\scene\layer\Layer.hpp"
#include "graphic\renderer\Renderer2D.hpp"

namespace silver::graphic
{
	class Layer2d : public Layer
	{
	public:

	private:
		std::unique_ptr<Renderer2D> renderer_;
		std::vector<Renderable2D> renderables_;
	};
}