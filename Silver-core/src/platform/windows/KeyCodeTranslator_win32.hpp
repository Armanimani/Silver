#pragma once

#include "input\KeyCode.hpp"

#include <map>

namespace silver::core
{
	class KeyCodeTranslator_win32
	{
	public:
		static KeyCode translate(const unsigned int key) noexcept;

	private:
		static std::map<const unsigned int, KeyCode> database_;
	};
}