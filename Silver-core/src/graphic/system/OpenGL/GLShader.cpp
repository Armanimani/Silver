#include "graphic\system\OpenGL\GLShader.hpp"

#include "util\io\FileReader.hpp"
#include "util\logger\Logger.hpp"

#include <GL\glew.h>

namespace silver::graphic
{
	GLShader::GLShader(const std::string& file)
	{
		parse_shaders_(file);
		compile();
	}

	GLShader::~GLShader()
	{
		glDeleteProgram(handle_);
	}

	void GLShader::bind() const
	{
		glUseProgram(handle_);
	}

	void GLShader::unbind() const
	{
		glUseProgram(0);
	}

	void GLShader::parse_shaders_(const std::string& file)
	{
		source_ = silver::core::FileReader::parse_GLShader(file);
	}

	void GLShader::compile()
	{
		handle_ = glCreateProgram();

		std::vector<uint> handles;

		if (!source_.vertex.empty())
		{
			handles.push_back(glCreateShader(GL_VERTEX_SHADER));
			compile_shader(handles[handles.size() - 1], source_.vertex);
			glAttachShader(handle_, handles[handles.size() - 1]);
		}
		if (!source_.fragment.empty())
		{
			handles.push_back(glCreateShader(GL_FRAGMENT_SHADER));
			compile_shader(handles[handles.size() - 1], source_.fragment);
			glAttachShader(handle_, handles[handles.size() - 1]);
		}

		glLinkProgram(handle_);
		glValidateProgram(handle_);
		check_program_status(handle_);

		for (auto &i : handles)
		{
			glDeleteShader(i);
		}
	}

	void GLShader::compile_shader(const uint32 shaderHandle, const std::string& code)
	{
		auto temp = code.c_str();
		glShaderSource(shaderHandle, 1, static_cast<const char**>(&temp), nullptr);
		glCompileShader(shaderHandle);
		check_shader_status(shaderHandle);
	}

	void GLShader::check_shader_status(const uint32 shaderID)
	{
		GLint status;
		glGetShaderiv(shaderID, GL_COMPILE_STATUS, &status);
		if (status != GL_TRUE)
		{
			GLint infoLogLength;
			glGetShaderiv(shaderID, GL_INFO_LOG_LENGTH, &infoLogLength);
			GLchar* buffer = new GLchar[infoLogLength];
			GLsizei bufferSize;
			glGetShaderInfoLog(shaderID, infoLogLength, &bufferSize, buffer);

			core::Logger::instance().log_error(std::string(buffer));
			delete[] buffer;
			throw SILVER_EXCEPTION_CRITICAL("Shader compilation failed");
		}
	}

	void GLShader::check_program_status(const uint32 programID)
	{
		GLint status;
		glGetProgramiv(programID, GL_LINK_STATUS, &status);
		if (status != GL_TRUE)
		{
			GLint infoLogLength;
			glGetProgramiv(programID, GL_INFO_LOG_LENGTH, &infoLogLength);
			GLchar* buffer = new GLchar[infoLogLength];
			GLsizei bufferSize;
			glGetProgramInfoLog(programID, infoLogLength, &bufferSize, buffer);

			core::Logger::instance().log_error(buffer);
			delete[] buffer;
			throw SILVER_EXCEPTION_CRITICAL("Program compilation failed");
		}
	}

	int32 GLShader::get_uniform_location_(const std::string& name) const
	{
		auto res = glGetUniformLocation(handle_, name.c_str());
		if (res < 0)
			throw SILVER_EXCEPTION_CRITICAL("Unable o get uniform location of " + name);
		return res;
	}

	void GLShader::set_uniform_(const std::string& name, const float value) const
	{
		glUniform1f(get_uniform_location_(name), value);
	}

	void GLShader::set_uniform_(const std::string& name, const vec2f value) const
	{
		glUniform2f(get_uniform_location_(name), value.x, value.y);
	}

	void GLShader::set_uniform_(const std::string& name, const vec3f value) const
	{
		glUniform3f(get_uniform_location_(name), value.x, value.y, value.z);
	}

	void GLShader::set_uniform_(const std::string& name, const vec4f value) const
	{
		glUniform4f(get_uniform_location_(name), value.x, value.y, value.z, value.a);
	}

	void GLShader::set_uniform_(const std::string& name, const int32 value) const
	{
		glUniform1i(get_uniform_location_(name), value);
	}

	void GLShader::set_uniform_(const std::string& name, const vec2i value) const
	{
		glUniform2i(get_uniform_location_(name), value.x, value.y);
	}

	void GLShader::set_uniform_(const std::string& name, const vec3i value) const
	{
		glUniform3i(get_uniform_location_(name), value.x, value.y, value.z);
	}

	void GLShader::set_uniform_(const std::string& name, const vec4i value) const
	{
		glUniform4i(get_uniform_location_(name), value.x, value.y, value.z, value.a);
	}

	void GLShader::set_uniform_(const std::string& name, const mat3 value) const
	{
		// TODO
	}

	void GLShader::set_uniform_(const std::string& name, const mat4 value) const
	{
		// TODO
	}

	void GLShader::set_uniform_(const std::string& name, const uint count, const float* value) const
	{
		// TODO
	}
	void GLShader::set_uniform_(const std::string& name, const uint count, const int32* value) const
	{
		// TODO
	}
}