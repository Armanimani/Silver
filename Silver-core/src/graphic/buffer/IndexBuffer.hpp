#pragma once

#include <memory>
#include <vector>

#include "common.hpp"
#include "graphic\buffer\Buffer.hpp"

namespace silver::graphic
{
	enum struct IndexBufferData
	{
		UNSIGNED_INT,
		UNSIGNED_SHORT
	};
	class IndexBuffer : public Buffer
	{
	public:
		static std::unique_ptr<IndexBuffer> create(const BufferMode mode = BufferMode::STATIC, const IndexBufferData dataType = IndexBufferData::UNSIGNED_INT);

		uint count() const noexcept;
		virtual uint dataType() const noexcept = 0;

	protected:
		uint count_;
		IndexBufferData dataType_;
	};
}