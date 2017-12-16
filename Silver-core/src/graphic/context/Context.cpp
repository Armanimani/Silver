#include "graphic\context\Context.hpp"

#include "graphic\system\OpenGL\GLContext.hpp"
#include "common.hpp"

namespace silver::core::graphic
{
	std::unique_ptr<Context> Context::s_instance_;
	Context* Context::instance()
	{
		if (!s_instance_)
		{
			throw SILVER_EXCEPTION_CRITICAL("Context must be created first before use");
		}
		return s_instance_.get();
	}

	void Context::init(const RenderingContext& renderingContext)
	{
		if (renderingContext == RenderingContext::OpenGL)
		{
			s_instance_ = std::make_unique<GLContext>();
		}
		else
		{
			throw SILVER_EXCEPTION_CRITICAL("Unsupported rendering context!");
		}
	}
}