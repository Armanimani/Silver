#pragma once

#include <string>

#include "common.hpp"

namespace silver::core
{
	class CriticalException
	{
	public:
		CriticalException(const std::string file, const int32 line, const std::string message) : file_(std::move(file)), line_(std::move(line)), message_(std::move(message)) {}

		std::string get() const;

	private:
		const std::string file_;
		const int32 line_;
		const std::string message_;
	};
}
