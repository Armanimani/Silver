#include "graphic\buffer\IndexBuffer.hpp"

#include "graphic\context\Context.hpp"
#include "graphic\system\OpenGL\GLIndexBuffer.hpp"
#include "common.hpp"

namespace silver::graphic
{
	std::unique_ptr<IndexBuffer> IndexBuffer::create(const BufferMode mode, const IndexBufferData dataType)
	{
		if (Context::instance()->API() == RenderingContext_API::OpenGL)
		{
			std::unique_ptr<IndexBuffer> p = std::make_unique<GLIndexBuffer>(mode, dataType);
			return p;
		}
		else
		{
			throw SILVER_EXCEPTION_CRITICAL("Unsupported Index Buffer platform");
		}
	}

	uint IndexBuffer::count() const noexcept
	{
		return count_;
	}
}