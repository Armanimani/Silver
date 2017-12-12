#include "graphic\system\Context.hpp"

#include "graphic\system\OpenGL\GLContext.hpp"
#include "common.hpp"

namespace silver::core::graphic
{
	RenderingContext Context::API_ = RenderingContext::OpenGL;

	Context::Context()
	{
	}

	Context::Context(const RenderingContext& renderingContext)
	{
		API_ = renderingContext;
	}

	void* Context::renderingContext()
	{
		switch (API_)
		{
			case (RenderingContext::OpenGL):
			{
				return GLContext::renderingContext();
			}
			case (RenderingContext::DirectX):
			{
				throw SILVER_EXCEPTION_CRITICAL("Unsupported rendering context!");
			}
		}
		return nullptr;
	}

	void Context::create(void* deviceContext)
	{
		switch (API_)
		{
			case (RenderingContext::OpenGL):
			{
				GLContext::create(deviceContext);
				break;
			}
			case (RenderingContext::DirectX):
			{
				throw SILVER_EXCEPTION_CRITICAL("Unsupported rendering context!");
			}
		}
	}

	void Context::release()
	{
		switch (API_)
		{
			case (RenderingContext::OpenGL):
			{
				GLContext::release();
				break;
			}
			case (RenderingContext::DirectX):
			{
				throw SILVER_EXCEPTION_CRITICAL("Unsupported rendering context!");
			}
		}
	}
}