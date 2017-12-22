#pragma once

#include <map>

#include "input\KeyCode.hpp"
#include "common.hpp"

namespace silver::core
{
	class KeyCodeTranslator_win32
	{
	public:
		static KeyCode translate(const uint key) noexcept;

	private:
		static std::map<const uint, KeyCode> database_;
	};
}