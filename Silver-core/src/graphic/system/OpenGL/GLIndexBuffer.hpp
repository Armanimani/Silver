#pragma once

#include "graphic\buffer\IndexBuffer.hpp"

namespace silver::graphic
{
	class GLIndexBuffer : public IndexBuffer
	{
	public:
		GLIndexBuffer(const BufferMode mode = BufferMode::STATIC, const IndexBufferData dataType = IndexBufferData::UNSIGNED_INT);
		~GLIndexBuffer();

		void bind() const noexcept override;
		void unbind() const noexcept override;
		void set_data(const void* dataAddress, const uint count) noexcept override;
		uint dataType() const noexcept override;
	};
}