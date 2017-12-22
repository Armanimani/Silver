#include "graphic\buffer\VertexBuffer.hpp"

#include "graphic\context\Context.hpp"
#include "graphic\system\OpenGL\GLVertexBuffer.hpp"
#include "common.hpp"

namespace silver::graphic
{
	std::unique_ptr<VertexBuffer> VertexBuffer::create(const BufferMode mode)
	{
		if (Context::instance()->API() == RenderingContext_API::OpenGL)
		{
			std::unique_ptr<VertexBuffer> p = std::make_unique<GLVertexBuffer>(mode);
			return p;
		}
		else
		{
			throw SILVER_EXCEPTION_CRITICAL("Unsupported Vertex Buffer platform");
		}
	}
}