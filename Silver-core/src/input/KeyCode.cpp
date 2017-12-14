#include "input\KeyCode.hpp"

namespace silver::core
{
	KeyCode operator|(KeyCode lhs, KeyCode rhs)
	{
		return static_cast<KeyCode>(static_cast<unsigned int>(lhs) | static_cast<unsigned int>(rhs));
	}

	KeyCode operator&(KeyCode lhs, KeyCode rhs)
	{
		return static_cast<KeyCode>(static_cast<unsigned int>(lhs) & static_cast<unsigned int>(rhs));
	}

	KeyCode& operator|=(KeyCode& lhs, KeyCode rhs)
	{
		lhs = static_cast<KeyCode>(static_cast<unsigned int>(lhs) | static_cast<unsigned int>(rhs));
		return lhs;
	}

	KeyCode& operator&=(KeyCode& lhs, KeyCode rhs)
	{
		lhs = static_cast<KeyCode>(static_cast<unsigned int>(lhs) & static_cast<unsigned int>(rhs));
		return lhs;
	}

	KeyCode operator|(KeyCode lhs, KeyModifier rhs)
	{
		return static_cast<KeyCode>(static_cast<unsigned int>(lhs) | static_cast<unsigned int>(rhs));
	}

	KeyCode operator&(KeyCode lhs, KeyModifier rhs)
	{
		return static_cast<KeyCode>(static_cast<unsigned int>(lhs) & static_cast<unsigned int>(rhs));
	}

	KeyCode& operator|=(KeyCode& lhs, KeyModifier rhs)
	{
		lhs = static_cast<KeyCode>(static_cast<unsigned int>(lhs) | static_cast<unsigned int>(rhs));
		return lhs;
	}

	KeyCode& operator&=(KeyCode& lhs, KeyModifier rhs)
	{
		lhs = static_cast<KeyCode>(static_cast<unsigned int>(lhs) & static_cast<unsigned int>(rhs));
		return lhs;
	}

	bool toBool(const KeyCode code)
	{
		return !(code == KeyCode::KEY_NO_CODE);
	}
}