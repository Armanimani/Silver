#pragma once

#include "common.hpp"
#include <memory>
#include "graphic/mesh/Mesh.hpp"

namespace silver::graphic
{
	class MeshCreator
	{
	public:
		static std::unique_ptr<Mesh> hello_triangle() noexcept;
		static std::unique_ptr<Mesh> rectangle(const float width, const float height) noexcept;
	};
}