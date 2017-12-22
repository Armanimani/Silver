#pragma once

#include <vector>
#include <memory>
#include <map>

#include "graphic\buffer\BufferStructure.hpp"

namespace silver::graphic
{
	class BufferLayout
	{
	public:
		static std::unique_ptr<BufferLayout> create();

		void push(const BufferData name, const BufferDataType dataType, const bool normalized = false);
		BufferData name(const uint index) const;
		//std::vector<Byte> apply(const RawMesh* mesh) const;

		virtual void bind() const = 0;

	protected:
		std::vector<BufferStructure> structures_;
		uint stride_;

		virtual void push_byte_(const BufferData name, const uint count, const bool normalized, const BufferDataType typeName) noexcept = 0;
		virtual	void push_float_(const BufferData name, const uint count, const bool normalized, const BufferDataType typeName) noexcept = 0;
		virtual void push_uint_(const BufferData name, const uint count, const bool normalized, const BufferDataType typeName) noexcept = 0;
	};
}