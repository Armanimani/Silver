#pragma once

#include "common.hpp"

namespace silver::graphic
{
	enum class BufferMode
	{
		STATIC,
		DYNAMIC
	};

	class Buffer
	{
	public:
		virtual void bind() const noexcept = 0;
		virtual void unbind() const noexcept= 0;
		virtual void set_data(const void* dataAddress, const uint size) noexcept = 0;

		uint size() const noexcept { return size_; }
		BufferMode mode() const noexcept { return mode_; }

	protected:
		uint handle_;
		uint size_;
		BufferMode mode_;
	};
}