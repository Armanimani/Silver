#include "graphic\system\OpenGL\GLBufferLayout.hpp"

#include "common.hpp"

#include <GL\glew.h>

namespace silver::graphic
{

	void GLBufferLayout::bind() const
	{
		for (auto &i : structures_)
		{
			glEnableVertexAttribArray(static_cast<GLuint>(i.name));
			glVertexAttribPointer(0, i.count, i.internalDataType, i.normalized, stride_ - i.size, reinterpret_cast<const void*>(i.offset));
		}
	}

	void GLBufferLayout::push_byte_(const BufferData name, const uint count, const bool normalized, const BufferDataType dataType) noexcept
	{
		auto size = static_cast<uint>(sizeof(Byte) * count);
		structures_.emplace_back(name, dataType, count, GL_BYTE, size, stride_, normalized);
		stride_ += size;
	}

	void GLBufferLayout::push_uint_(const BufferData name, const uint count, const bool normalized, const BufferDataType dataType) noexcept
	{
		auto size = static_cast<uint>(sizeof(uint) * count);
		structures_.emplace_back(name, dataType, count, GL_UNSIGNED_INT, size, stride_, normalized);
		stride_ += size;;
	}

	void GLBufferLayout::push_float_(const BufferData name, const uint count, const bool normalized, const BufferDataType dataType) noexcept
	{
		auto size = static_cast<uint>(sizeof(float) * count);
		structures_.emplace_back(name, dataType, count, GL_FLOAT, size, stride_, normalized);
		stride_ += size;
	}
}