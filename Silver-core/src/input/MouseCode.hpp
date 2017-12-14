#pragma once

#include "input\KeyModifier.hpp"

namespace silver::core
{
	enum struct MouseCode
	{
		MOUSE_NO_CODE = 0x00,
		MOUSE_LEFT = 0x01,
		MOUSE_RIGHT = 0x02,
		MOUSE_MIDDLE = 0x03,
		MOUSE_WHEEL = 0x04,
	};

	MouseCode operator|(MouseCode lhs, MouseCode rhs);
	MouseCode operator&(MouseCode lhs, MouseCode rhs);
	MouseCode& operator|=(MouseCode& lhs, MouseCode rhs);
	MouseCode& operator&=(MouseCode& lhs, MouseCode rhs);
	MouseCode operator|(MouseCode lhs, KeyModifier rhs);
	MouseCode operator&(MouseCode lhs, KeyModifier rhs);
	MouseCode& operator|=(MouseCode& lhs, KeyModifier rhs);
	MouseCode& operator&=(MouseCode& lhs, KeyModifier rhs);

	bool toBool(const MouseCode code);
}