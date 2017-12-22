#pragma once

#include "graphic/buffer/VertexArray.hpp"
#include "graphic/buffer/IndexBuffer.hpp"
#include <memory>

namespace silver::graphic
{
	struct Mesh
	{
		Mesh(std::unique_ptr<VertexArray>&& vertexA, std::unique_ptr<IndexBuffer>&& indexB) : vertexArray(std::move(vertexA)), indexBuffer(std::move(indexB)) {}

		std::unique_ptr<VertexArray> vertexArray;
		std::unique_ptr<IndexBuffer> indexBuffer;
	};
}