#include "graphic\system\OpenGL\GLVertexArray.hpp"

#include <GL\glew.h>

namespace silver::graphic
{
	GLVertexArray::GLVertexArray()
	{
		glGenVertexArrays(1, &handle_);
	}

	GLVertexArray::~GLVertexArray()
	{
		glDeleteBuffers(1, &handle_);
	}

	void GLVertexArray::bind() const noexcept
	{
		glBindVertexArray(handle_);
	}

	void GLVertexArray::unbind() const noexcept
	{
		glBindVertexArray(0);
	}
}