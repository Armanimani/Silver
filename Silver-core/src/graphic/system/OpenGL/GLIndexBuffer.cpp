#include "graphic\system\OpenGL\GLIndexBuffer.hpp"

#include <GL\glew.h>

namespace silver::graphic
{
	GLIndexBuffer::GLIndexBuffer(const BufferMode mode, const IndexBufferData dataType)
	{
		mode_ = mode;
		dataType_ = dataType;
		glGenBuffers(1, &handle_);
	}

	GLIndexBuffer::~GLIndexBuffer()
	{
		glDeleteBuffers(1, &handle_);
	}

	void GLIndexBuffer::bind() const noexcept
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, handle_);
	}

	void GLIndexBuffer::unbind() const noexcept
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	}

	void GLIndexBuffer::set_data(const void* dataAddress, const uint count) noexcept
	{
		count_ = count;
		size_ = static_cast<uint>([] (const IndexBufferData dataType) { return (dataType == IndexBufferData::UNSIGNED_INT) ? sizeof(uint) : sizeof(ushort); }(dataType_));
		size_ *= count;
		uint drawMode = [] (const BufferMode mode) { return (mode == BufferMode::STATIC) ? GL_STATIC_DRAW : GL_DYNAMIC_DRAW; }(mode_);

		bind();
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, size_, dataAddress, drawMode);
		unbind();
	}

	uint GLIndexBuffer::dataType() const noexcept
	{
		return (dataType_ == IndexBufferData::UNSIGNED_INT) ? GL_UNSIGNED_INT : GL_UNSIGNED_SHORT;
	}

}