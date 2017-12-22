#include "graphic\system\OpenGL\GLContext.hpp"

#include "common.hpp"
#include "config.hpp"

#ifdef _WIN32
	#include <Windows.h>
#endif

#ifdef SILVER_DEBUG
	#include "graphic/system/OpenGL/GLDebug.hpp"
#endif


#include <GL\glew.h>

namespace silver::graphic
{
	void* GLContext::s_deviceContext_;
	void* GLContext::s_renderingContext_;

	//void (APIENTRY *DEBUGPROC)(GLenum source,
	//	GLenum type,
	//	GLuint id,
	//	GLenum severity,
	//	GLsizei length,
	//	const GLchar *message,
	//	void *userParam)
	//{

	//}

	void GLContext::create(void* deviceContext)
	{
		s_deviceContext_ = deviceContext;

		#ifdef _WIN32
			auto renderingContext_ = wglCreateContext(static_cast<HDC>(s_deviceContext_));
			if (!renderingContext_)
			{
				throw SILVER_EXCEPTION_CRITICAL("Unable create OpenGL rendering context.");
			}

			if (!wglMakeCurrent(static_cast<HDC>(s_deviceContext_), renderingContext_))
			{
				throw SILVER_EXCEPTION_CRITICAL("Unable to make OpenGL the current rendering context.");
			}

			if (glewInit() != GLEW_OK)
			{
				throw SILVER_EXCEPTION_CRITICAL("Unable to initialize glew.");
			}

		#else
			throw SILVER_EXCEPTION_CRITICAL("Unsupported platform!");
		#endif

		#ifdef SILVER_DEBUG
			glEnable(GL_DEBUG_OUTPUT);
			glDebugMessageCallback(GLDebug::debugger_callback, nullptr);
			glDebugMessageControl(GL_DONT_CARE, GL_DONT_CARE, GL_DONT_CARE, 0, nullptr, GL_TRUE);
		#endif
			
	}

	void GLContext::release()
	{
		#ifdef _WIN32
			if (!wglMakeCurrent(nullptr, nullptr))
			{
				throw SILVER_EXCEPTION_CRITICAL("Unable to release OpneGL rendering context from the current context.");
			}

			if (!wglDeleteContext(static_cast<HGLRC>(s_renderingContext_)))
			{
				throw SILVER_EXCEPTION_CRITICAL("Unable to delete OpenGL rendering context.");
			}
		#else
		throw SILVER_EXCEPTION_CRITICAL("Unsupported platform!");
		#endif
	}

	void GLContext::swap_buffer() const noexcept
	{
		#ifdef _WIN32
			SwapBuffers(static_cast<HDC>(s_deviceContext_));
		#else
			throw SILVER_EXCEPTION_CRITICAL("Unsupported platform!");
		#endif
	}

	void GLContext::clear() const noexcept
	{
		glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
		glClearColor(0.0, 0.0, 0.0, 1.0);
	}
}