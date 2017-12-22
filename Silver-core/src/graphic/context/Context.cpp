#include "graphic\context\Context.hpp"

#include "graphic\system\OpenGL\GLContext.hpp"
#include "common.hpp"

namespace silver::graphic
{
	std::unique_ptr<Context> Context::s_instance_;
	RenderingContext_API Context::s_renderingAPI_;
	Context* Context::instance()
	{
		if (!s_instance_)
		{
			throw SILVER_EXCEPTION_CRITICAL("Context must be created first before use");
		}
		return s_instance_.get();
	}

	RenderingContext_API Context::API() noexcept
	{
		return s_renderingAPI_;
	}

	void Context::init(const RenderingContext_API& renderingContext_API)
	{
		s_renderingAPI_ = renderingContext_API;
		if (renderingContext_API == RenderingContext_API::OpenGL)
		{
			s_instance_ = std::make_unique<GLContext>();
		}
		else
		{
			throw SILVER_EXCEPTION_CRITICAL("Unsupported rendering context API!");
		}
	}
}