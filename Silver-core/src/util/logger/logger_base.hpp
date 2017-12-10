#pragma once

#include <string>
#include <optional>

namespace silver::core::impl
{
	template <typename T>
	static std::string toString(T&& object)
	{
		return { "Unsupported type {" + std::string(typeid(object).name()) + "}" };
	}

	static std::string toString(std::string& object)
	{
		return { object };
	}

	template<std::size_t N>
	static std::string toString(const char (&object)[N])
	{
		return { object };
	}

	static std::string toString(const int object)
	{
		return std::to_string(object);
	}

	static std::string toString(const unsigned int object)
	{
		return std::to_string(object);
	}

	static std::string toString(const float object)
	{
		return std::to_string(object);
	}

	static std::string toString(const double object)
	{
		return std::to_string(object);
	}
}