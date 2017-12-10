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

	static std::string toString(const std::string& object)
	{
		return { object };
	}

	template<std::size_t N>
	static std::string toString(const char (&object)[N])
	{
		return { object };
	}

	template<std::size_t N>
	static std::string toString(char(&object)[N])
	{
		return { object };
	}
}