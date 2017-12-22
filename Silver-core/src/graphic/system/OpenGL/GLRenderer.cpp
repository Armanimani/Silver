#include "graphic\system\OpenGL\GLRenderer.hpp"
#include "util\logger\Logger.hpp"

#include <GL\glew.h>

namespace silver::graphic
{
	void GLRenderer::init_internal() const noexcept
	{
		log_version_();
		set_depth_test(true);
		glEnable(GL_CULL_FACE);
	}

	void GLRenderer::present_internal() const noexcept
	{
		Context::instance()->swap_buffer();
	}

	void GLRenderer::set_viewport_internal(const vec2ui& position, const vec2ui& size) const noexcept
	{
		glViewport(position.x, position.y, size.x, size.y);
	}

	void GLRenderer::set_depth_test_internal(const bool state) const noexcept
	{
		(state) ? glEnable(GL_DEPTH_TEST) : glDisable(GL_DEPTH_TEST);
	}

	void GLRenderer::clear_buffer_internal(const RendererBuffer buffer) const noexcept
	{
		switch (buffer)
		{
			case RendererBuffer::COLOR_BUFFER:
			{
				glClear(GL_COLOR_BUFFER_BIT);
				break;
			}
			case RendererBuffer::DEPTH_BUFFER:
			{
				glClear(GL_DEPTH_BUFFER_BIT);
				break;
			}
		}
	}

	void GLRenderer::log_version_() const noexcept
	{
		auto version = glGetString(GL_VERSION);
		auto vendor = std::string(reinterpret_cast<const char*>(glGetString(GL_VENDOR)));
		auto renderer = std::string(reinterpret_cast<const char*>(glGetString(GL_RENDERER)));

		GLint minor {};
		GLint major {};
		glGetIntegerv(GL_MAJOR_VERSION, &major);
		glGetIntegerv(GL_MINOR_VERSION, &minor);

		std::string log { "Initializing OpenGL --  Version: " + std::to_string(major) + "." + std::to_string(minor) + "     Vendor: " + vendor + "     Renderer:" + renderer };
		core::Logger::instance().log_information(log);
	}
}