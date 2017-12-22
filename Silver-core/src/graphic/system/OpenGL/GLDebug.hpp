#pragma once

#include "util/logger/Logger.hpp"

#include <GL\glew.h>

namespace silver::graphic
{
	class GLDebug
	{
	public:
		static void CALLBACK debugger_callback(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar *msg, const void *data)
		{
			std::string log { "source = " + translate_source(source) + "    type = " + translate_type(type) + "    severity = " + translate_severity(severity) + "    " + msg };
			switch (severity)
			{
				case GL_DEBUG_SEVERITY_HIGH:
				{
					core::Logger::instance().log_error(log);
					break;
				}
				case GL_DEBUG_SEVERITY_MEDIUM:
				case GL_DEBUG_SEVERITY_LOW:
				{
					core::Logger::instance().log_warning(log);
					break;
				}
				case GL_DEBUG_SEVERITY_NOTIFICATION:
				{
					core::Logger::instance().log_information(log);
					break;
				}
				default:
				{
					core::Logger::instance().log_error(log);
					break;
				}
			}
		}

	private:
		static std::string translate_type(GLenum type)
		{
			switch (type)
			{
				default:
					return "Unknown";
				case GL_DEBUG_TYPE_ERROR:
					return"Error";
				case GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR:
					return "Deprecated behavior";
				case GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR:
					return "Undefined behavior";
				case GL_DEBUG_TYPE_PORTABILITY:
					return "Portability issue";
				case GL_DEBUG_TYPE_PERFORMANCE:
					return "Performance issue";
				case GL_DEBUG_TYPE_MARKER:
					return "Stream annotation";
				case GL_DEBUG_TYPE_OTHER_ARB:
					return "Other";
			}
		}

		static std::string translate_source(GLenum source)
		{
			switch (source)
			{
				default:
					return "Unknown";
				case GL_DEBUG_SOURCE_API:
					return "API";
				case GL_DEBUG_SOURCE_WINDOW_SYSTEM:
					return "Window system";
				case GL_DEBUG_SOURCE_SHADER_COMPILER:
					return "Shader compiler";
				case GL_DEBUG_SOURCE_THIRD_PARTY:
					return "Third party";
				case GL_DEBUG_SOURCE_APPLICATION:
					return "Application";
				case GL_DEBUG_SOURCE_OTHER:
					return "Other";
			}
		}

		static std::string translate_severity(GLenum severity)
		{
			switch (severity)
			{
				default:
					return "Unknown";
				case GL_DEBUG_SEVERITY_HIGH:
					return "High";
				case GL_DEBUG_SEVERITY_MEDIUM:
					return "Medium";
				case GL_DEBUG_SEVERITY_LOW:
					return "Low";
				case GL_DEBUG_SEVERITY_NOTIFICATION:
					return "Notification";
			}
		}
	};
}