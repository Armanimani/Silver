#pragma once

#include "graphic\buffer\Buffer.hpp"
#include "graphic\buffer\VertexBuffer.hpp"

namespace silver::graphic
{
	class VertexArray
	{
	public:
		static std::unique_ptr<VertexArray> create();

		virtual void bind() const noexcept = 0;
		virtual void unbind() const noexcept = 0;

		void set_buffer(std::unique_ptr<VertexBuffer>&& buffer, std::unique_ptr<BufferLayout>&& layout);

	protected:
		uint handle_;
		std::unique_ptr<VertexBuffer> buffer_;
		std::unique_ptr<BufferLayout> layout_;
	};
}