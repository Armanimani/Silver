#include "input\MouseCode.hpp"

namespace silver::core
{
	MouseCode operator|(MouseCode lhs, MouseCode rhs)
	{
		return static_cast<MouseCode>(static_cast<unsigned int>(lhs) | static_cast<unsigned int>(rhs));
	}

	MouseCode operator&(MouseCode lhs, MouseCode rhs)
	{
		return static_cast<MouseCode>(static_cast<unsigned int>(lhs) & static_cast<unsigned int>(rhs));
	}

	MouseCode& operator|=(MouseCode& lhs, MouseCode rhs)
	{
		lhs = static_cast<MouseCode>(static_cast<unsigned int>(lhs) | static_cast<unsigned int>(rhs));
		return lhs;
	}

	MouseCode& operator&=(MouseCode& lhs, MouseCode rhs)
	{
		lhs = static_cast<MouseCode>(static_cast<unsigned int>(lhs) & static_cast<unsigned int>(rhs));
		return lhs;
	}

	MouseCode operator|(MouseCode lhs, KeyModifier rhs)
	{
		return static_cast<MouseCode>(static_cast<unsigned int>(lhs) | static_cast<unsigned int>(rhs));
	}

	MouseCode operator&(MouseCode lhs, KeyModifier rhs)
	{
		return static_cast<MouseCode>(static_cast<unsigned int>(lhs) & static_cast<unsigned int>(rhs));
	}

	MouseCode& operator|=(MouseCode& lhs, KeyModifier rhs)
	{
		lhs = static_cast<MouseCode>(static_cast<unsigned int>(lhs) | static_cast<unsigned int>(rhs));
		return lhs;
	}

	MouseCode& operator&=(MouseCode& lhs, KeyModifier rhs)
	{
		lhs = static_cast<MouseCode>(static_cast<unsigned int>(lhs) & static_cast<unsigned int>(rhs));
		return lhs;
	}

	bool toBool(const MouseCode code)
	{
		return !(code == MouseCode::MOUSE_NO_CODE);
	}
}