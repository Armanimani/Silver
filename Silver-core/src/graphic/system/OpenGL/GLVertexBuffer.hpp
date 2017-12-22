#pragma once

#include "graphic\system\OpenGL\GLBufferLayout.hpp"
#include "graphic\buffer\VertexBuffer.hpp"

namespace silver::graphic
{
	class GLVertexBuffer : public VertexBuffer
	{
	public:
		GLVertexBuffer(const BufferMode mode);
		~GLVertexBuffer();

		void bind() const noexcept override;
		void unbind() const noexcept override;
		void set_data(const void* dataAddress, const uint size) noexcept override;
	};
}