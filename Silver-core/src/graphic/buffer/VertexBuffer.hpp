#pragma once

#include <memory>
#include <vector>

#include "graphic/buffer/BufferLayout.hpp"

#include "graphic/buffer/Buffer.hpp"

namespace silver::graphic
{
	class VertexBuffer : public Buffer
	{
	public:
		static std::unique_ptr<VertexBuffer> create(const BufferMode mode = BufferMode::STATIC);
	};
}