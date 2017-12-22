#include "graphic\system\OpenGL\GLVertexBuffer.hpp"

#include <GL\glew.h>

namespace silver::graphic
{
	GLVertexBuffer::GLVertexBuffer(const BufferMode mode)
	{
		mode_ = std::move(mode);
		glGenBuffers(1, &handle_);
	}

	GLVertexBuffer::~GLVertexBuffer()
	{
		glDeleteBuffers(1, &handle_);
	}

	void GLVertexBuffer::bind() const noexcept
	{
		glBindBuffer(GL_ARRAY_BUFFER, handle_);
	}

	void GLVertexBuffer::unbind() const noexcept
	{
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}

	void GLVertexBuffer::set_data(const void* dataAddress, const uint size) noexcept
	{
		bind();
		uint drawMode = [] (const BufferMode mode) { return (mode == BufferMode::STATIC) ? GL_STATIC_DRAW : GL_DYNAMIC_DRAW; }(mode_);
		glBufferData(GL_ARRAY_BUFFER, size, dataAddress, drawMode);
		unbind();
	}

}