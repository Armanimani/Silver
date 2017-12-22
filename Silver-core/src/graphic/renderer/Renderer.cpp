#include "graphic\renderer\Renderer.hpp"

#include "graphic\system\OpenGL\GLRenderer.hpp"
#include "common.hpp"

namespace silver::graphic
{
	std::unique_ptr<Renderer> Renderer::s_instance_;

	Renderer* Renderer::instance() noexcept
	{
		if (!s_instance_)
			return s_instance_.get();
		return nullptr;
	}

	void Renderer::init()
	{
		auto context = Context::instance()->API();
		if (context == RenderingContext_API::OpenGL)
		{
			s_instance_ = std::make_unique<GLRenderer>();
		}
		else
		{
			throw SILVER_EXCEPTION_CRITICAL("Unsupported rendering context!");
		}
		s_instance_->init_internal();
	}

	void Renderer::present() noexcept
	{
		s_instance_->present_internal();
	}

	void Renderer::set_viewport(const vec2ui& position, const vec2ui& size) noexcept
	{
		s_instance_->set_viewport_internal(position, size);
	}

	void Renderer::set_depth_test(const bool state) noexcept
	{
		s_instance_->set_depth_test_internal(state);
	}

	void Renderer::clear_buffer(const RendererBuffer buffer) noexcept
	{
		s_instance_->clear_buffer_internal(buffer);
	}

}