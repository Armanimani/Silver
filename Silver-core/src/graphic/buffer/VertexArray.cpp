#include "graphic\buffer\VertexArray.hpp"

#include "graphic\system\OpenGL\GLVertexArray.hpp"
#include "graphic\context\Context.hpp"
#include "common.hpp"

namespace silver::graphic
{
	std::unique_ptr<VertexArray> VertexArray::create()
	{
		if (Context::instance()->API() == RenderingContext_API::OpenGL)
		{
			std::unique_ptr<VertexArray> p = std::make_unique<GLVertexArray>();
			return p;
		}
		else
		{
			throw SILVER_EXCEPTION_CRITICAL("Unsupported Vertex Array platform");
		}
	}

	void VertexArray::set_buffer(std::unique_ptr<VertexBuffer>&& buffer, std::unique_ptr<BufferLayout>&& layout)
	{
		buffer_ = std::move(buffer);
		layout_ = std::move(layout);

		bind();
		buffer_->bind();
		layout_->bind();
		unbind();
	}
}