#include "graphic\system\OpenGL\GLContext.hpp"

#include <GL\glew.h>

#include "common.hpp"

#ifdef _WIN32
	#include <Windows.h>
#endif

namespace silver::core::graphic
{
	void* GLContext::deviceContext_;
	void* GLContext::renderingContext_;

	void GLContext::create(void* deviceContext)
	{
		//glewInit();
		deviceContext_ = deviceContext;

		#ifdef _WIN32
			auto renderingContext_ = wglCreateContext(static_cast<HDC>(deviceContext_));
			if (!renderingContext_)
			{
				throw SILVER_EXCEPTION_CRITICAL("Unable create OpenGL rendering context.");
			}

			if (!wglMakeCurrent(static_cast<HDC>(deviceContext_), renderingContext_))
			{
				throw SILVER_EXCEPTION_CRITICAL("Unable to make OpenGL the current rendering context.");
			}
		#else
			throw SILVER_EXCEPTION_CRITICAL("Unsupported platform!");
		#endif
	}

	void GLContext::release()
	{
		#ifdef _WIN32
			if (!wglMakeCurrent(nullptr, nullptr))
			{
				throw SILVER_EXCEPTION_CRITICAL("Unable to release OpneGL rendering context from the current context.");
			}

			if (!wglDeleteContext(static_cast<HGLRC>(renderingContext_)))
			{
				throw SILVER_EXCEPTION_CRITICAL("Unable to delete OpenGL rendering context.");
			}
		#else
		throw SILVER_EXCEPTION_CRITICAL("Unsupported platform!");
		#endif
	}
}