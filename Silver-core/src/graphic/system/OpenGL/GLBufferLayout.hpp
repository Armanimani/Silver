#pragma once

#include <vector>

#include "graphic\buffer\BufferStructure.hpp"
#include "graphic\buffer\BufferLayout.hpp"

namespace silver::graphic
{
	class GLBufferLayout : public BufferLayout
	{
	public:
		void bind() const override;

	private:
		void push_byte_(const BufferData name, const uint count, const bool normalized, const BufferDataType dataType) noexcept override;
		void push_float_(const BufferData name, const uint count, const bool normalized, const BufferDataType dataType) noexcept override;
		void push_uint_(const BufferData name, const uint count, const bool normalized, const BufferDataType dataType) noexcept override;
	};
}