#pragma once

#include <string>

#include "common.hpp"

namespace silver::graphic
{
	enum class BufferData
	{
		POSITION = 0,
		COLOR = 1,
		NORMAL = 2,
		TEXTURE = 3,
		TANGENT = 4,
		BINORMAL = 5,
	};

	enum class BufferDataType
	{
		BYTE = 0,
		VEC2B = 1,
		VEC3B = 2,
		VEC4B = 3,
		UNSIGNED_INT = 4,
		VEC2UI = 5,
		VEC3UI = 6,
		VEC4UI = 7,
		FLOAT = 8,
		VEC2F = 9,
		VEC3F = 10,
		VEC4F = 11,
	};

	struct BufferStructure
	{
		BufferStructure(const BufferData name, const BufferDataType dataType, const uint count, const uint internalDataType, const uint size, const uint offset, const bool normalized = false) : name(std::move(name)), dataType(std::move(dataType)), count(std::move(count)), internalDataType(std::move(internalDataType)), size(std::move(size)), offset(std::move(offset)), normalized(std::move(normalized)) {}

		BufferData name;
		BufferDataType dataType;
		uint count;
		uint internalDataType;
		uint size;
		uint offset;
		bool normalized;
	};
}