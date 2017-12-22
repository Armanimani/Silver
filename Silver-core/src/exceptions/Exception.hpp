#pragma once

#include <string>

namespace silver::core
{
	template <typename T>
	class Exception
	{
	public:
		Exception(const std::string file, const int32 line, const T object) : file_(std::move(file)), line_(std::move(line)), object_(std::move(object)) {}

		T get() const;
		std::string get_info() const;

	private:
		const std::string file_;
		const int32 line_;
		const T object_;
	};

	template<typename T>
	T Exception<T>::get() const
	{
		return object_;
	}

	template <typename T>
	std::string Exception<T>::get_info() const
	{
		return std::string("@ " + file_ + ':' + std::to_string(line_));
	}
}