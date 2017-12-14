#pragma once

namespace silver::core
{
	enum class KeyModifier : int
	{
		KEY_MASK = 0xFF << 24,
		KEY_REMOVE_MASK = 0xFF,
		KEY_SHIFT = 1 << 25,
		KEY_ALT = 1 << 26,
		KEY_CTRL = 1 << 27,
		KEY_WIN = 1 << 28,
	};
}