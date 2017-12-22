#pragma once

#include "graphic\mesh\Mesh.hpp"

namespace silver::graphic
{
	class Renderable2D
	{
	public:
		Renderable2D(Mesh* mesh) : mesh_(mesh) {};

		Mesh* mesh() const noexcept { return mesh_; }

	private:
		Mesh* mesh_;
	};
}