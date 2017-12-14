#include "util\translator\Translator.hpp"

namespace silver::core
{
	std::map<const KeyCode, std::string> Translator::keyCodeDatabase_
	{
		{ KeyCode::KEY_NO_CODE, "NoCode" },

		{ KeyCode::KEY_A, "A" },
		{ KeyCode::KEY_B, "B" },
		{ KeyCode::KEY_C, "C" },
		{ KeyCode::KEY_D, "D" },
		{ KeyCode::KEY_E, "E" },
		{ KeyCode::KEY_F, "F" },
		{ KeyCode::KEY_G, "G" },
		{ KeyCode::KEY_H, "H" },
		{ KeyCode::KEY_I, "I" },
		{ KeyCode::KEY_J, "J" },
		{ KeyCode::KEY_K, "K" },
		{ KeyCode::KEY_L, "L" },
		{ KeyCode::KEY_M, "M" },
		{ KeyCode::KEY_N, "N" },
		{ KeyCode::KEY_O, "O" },
		{ KeyCode::KEY_P, "P" },
		{ KeyCode::KEY_Q, "Q" },
		{ KeyCode::KEY_R, "R" },
		{ KeyCode::KEY_S, "S" },
		{ KeyCode::KEY_T, "T" },
		{ KeyCode::KEY_U, "U" },
		{ KeyCode::KEY_V, "V" },
		{ KeyCode::KEY_W, "W" },
		{ KeyCode::KEY_X, "X" },
		{ KeyCode::KEY_Y, "Y" },
		{ KeyCode::KEY_Z, "Z" },

		{ KeyCode::KEY_0, "0" },
		{ KeyCode::KEY_1, "1" },
		{ KeyCode::KEY_2, "2" },
		{ KeyCode::KEY_3, "3" },
		{ KeyCode::KEY_4, "4" },
		{ KeyCode::KEY_5, "5" },
		{ KeyCode::KEY_6, "6" },
		{ KeyCode::KEY_7, "7" },
		{ KeyCode::KEY_8, "8" },
		{ KeyCode::KEY_9, "9" },

		{ KeyCode::KEY_F1, "F1" },
		{ KeyCode::KEY_F2, "F2" },
		{ KeyCode::KEY_F3, "F3" },
		{ KeyCode::KEY_F4, "F4" },
		{ KeyCode::KEY_F5, "F5" },
		{ KeyCode::KEY_F6, "F6" },
		{ KeyCode::KEY_F7, "F7" },
		{ KeyCode::KEY_F8, "F8" },
		{ KeyCode::KEY_F9, "F9" },
		{ KeyCode::KEY_F10, "F10" },
		{ KeyCode::KEY_F11, "F11" },
		{ KeyCode::KEY_F12, "F12" },
		{ KeyCode::KEY_F13, "F13" },
		{ KeyCode::KEY_F14, "F14" },
		{ KeyCode::KEY_F15, "F15" },
		{ KeyCode::KEY_F16, "F16" },
		{ KeyCode::KEY_F17, "F17" },
		{ KeyCode::KEY_F18, "F18" },
		{ KeyCode::KEY_F19, "F19" },
		{ KeyCode::KEY_F20, "F20" },
		{ KeyCode::KEY_F21, "F21" },
		{ KeyCode::KEY_F22, "F22" },
		{ KeyCode::KEY_F23, "F23" },
		{ KeyCode::KEY_F24, "F24" },

		{ KeyCode::KEY_NUM0, "Num0" },
		{ KeyCode::KEY_NUM1, "Num1" },
		{ KeyCode::KEY_NUM2, "Num2" },
		{ KeyCode::KEY_NUM3, "Num3" },
		{ KeyCode::KEY_NUM4, "Num4" },
		{ KeyCode::KEY_NUM5, "Num5" },
		{ KeyCode::KEY_NUM6, "Num6" },
		{ KeyCode::KEY_NUM7, "Num7" },
		{ KeyCode::KEY_NUM8, "Num8" },
		{ KeyCode::KEY_NUM9, "Num9" },

		{ KeyCode::KEY_NUMMULTIPLY, "NumMultiply" },
		{ KeyCode::KEY_NUMDIVIDE, "NumDivide" },
		{ KeyCode::KEY_NUMADD, "NumAdd" },
		{ KeyCode::KEY_NUMSUBTRACT, "NumSubtract" },

		{ KeyCode::KEY_BACKSPACE, "Backspace" },
		{ KeyCode::KEY_TAB, "Tab" },
		{ KeyCode::KEY_SPACE, "Space" },
		{ KeyCode::KEY_ENTER, "Enter" },
		{ KeyCode::KEY_CLEAR, "Clear" },
		{ KeyCode::KEY_PAUSE, "Pause" },
		{ KeyCode::KEY_ESCAPE, "Escape" },

		{ KeyCode::KEY_PAGEUP, "PageUp" },
		{ KeyCode::KEY_PAGEDOWN, "PageDown" },
		{ KeyCode::KEY_END, "End" },
		{ KeyCode::KEY_HOME, "Home" },
		{ KeyCode::KEY_INSERT, "Insert" },
		{ KeyCode::KEY_DELETE, "Delete" },
		{ KeyCode::KEY_MULTIPLY, "Multiply" },
		{ KeyCode::KEY_DIVIDE, "Divide" },
		{ KeyCode::KEY_ADD, "Add" },
		{ KeyCode::KEY_SUBTRACT, "Subtract" },
		{ KeyCode::KEY_SEPARATOR, "Separator" },
		{ KeyCode::KEY_DECIMAL, "Decimal" },

		{ KeyCode::KEY_UP, "Up" },
		{ KeyCode::KEY_DOWN, "Down" },
		{ KeyCode::KEY_LEFT, "Left" },
		{ KeyCode::KEY_RIGHT, "Right" },

		{ KeyCode::KEY_SELECT, "Select" },
		{ KeyCode::KEY_PRINTSCREEN, "PrintScreen" },
		{ KeyCode::KEY_SNAPSHOT, "Snapshot" },
		{ KeyCode::KEY_EXE, "Execute" },
		{ KeyCode::KEY_HELP, "Help" },
		{ KeyCode::KEY_SLEEP, "Sleep" },

		{ KeyCode::KEY_SCROLLLOCK, "ScrollLock" },
		{ KeyCode::KEY_CAPSLOCK, "CapsLock" },

		{ KeyCode::KEY_OEM_NUMEQUAL, "OemNumEqual" },
		{ KeyCode::KEY_OEM_DICTIONARY, "OemDictionary" },
		{ KeyCode::KEY_OEM_UNREGISTER, "OemUnregister" },
		{ KeyCode::KEY_OEM_REGISTER, "OemRegister" },
		{ KeyCode::KEY_OEM_LOYAYUBI, "OemLOyayubi" },
		{ KeyCode::KEY_OEM_ROYAYUBI, "OemROyayubi" },
		{ KeyCode::KEY_OEM_PLUS, "OemPlus" },
		{ KeyCode::KEY_OEM_COMMA, "OemComma" },
		{ KeyCode::KEY_OEM_MINUS, "OemMinus" },
		{ KeyCode::KEY_OEM_PERIOD, "OemPeriod" },
		{ KeyCode::KEY_OEM1, "Oem1" },
		{ KeyCode::KEY_OEM2, "Oem2" },
		{ KeyCode::KEY_OEM3, "Oem3" },
		{ KeyCode::KEY_OEM4, "Oem4" },
		{ KeyCode::KEY_OEM5, "Oem5" },
		{ KeyCode::KEY_OEM6, "Oem6" },
		{ KeyCode::KEY_OEM7, "Oem7" },
		{ KeyCode::KEY_OEM8, "Oem8" },
		{ KeyCode::KEY_OEM_AX, "OemAx" },
		{ KeyCode::KEY_OEM102, "Oem102" },

		{ KeyCode::KEY_BROWSER_BACK, "BrowserBack" },
		{ KeyCode::KEY_BROWSER_FORWARD, "BrowserForward" },
		{ KeyCode::KEY_BROWSER_REFRESH, "BrowserRefresh" },
		{ KeyCode::KEY_BROWSER_STOP, "BrowserStop" },
		{ KeyCode::KEY_BROWSER_SEARCH, "BrowserSearch" },
		{ KeyCode::KEY_BROWSER_FAVORITE, "BrowserFavorite" },
		{ KeyCode::KEY_BROWSER_HOME, "BrowserHome" },

		{ KeyCode::KEY_VOLUME_UP, "VolumeUp" },
		{ KeyCode::KEY_VOLUME_DOWN, "VolumeDown" },
		{ KeyCode::KEY_VOLUME_MUTE, "VolumeMute" },

		{ KeyCode::KEY_MEDIA_NEXT, "MediaNext" },
		{ KeyCode::KEY_MEDIA_PREV, "MediaPrev" },
		{ KeyCode::KEY_MEDIA_STOP, "MediaStop" },
		{ KeyCode::KEY_MEDIA_PLAY_PAUSE, "MediaPlayPause" },
		{ KeyCode::KEY_MEDIA_SELECT, "MediaSelect" },

		{ KeyCode::KEY_LAUNCH_APP1, "LaunchApp1" },
		{ KeyCode::KEY_LAUNCH_APP2, "LaunchApp2" },
		{ KeyCode::KEY_LAUNCH_MAIL, "LaunchMail" },

		{ KeyCode::KEY_APPLICATION, "Application" },

		{ KeyCode::KEY_RSHIFT, "RightShift" },
		{ KeyCode::KEY_RALT, "RightAlt" },
		{ KeyCode::KEY_RCTRL, "RightCtrl" },
		{ KeyCode::KEY_RWIN, "RightWin" },
		{ KeyCode::KEY_LSHIFT, "LeftShift" },
		{ KeyCode::KEY_LALT, "LeftAlt" },
		{ KeyCode::KEY_LCTRL, "LeftCtrl" },
		{ KeyCode::KEY_LWIN, "LeftWin" },

		{ KeyCode::KEY_SHIFT, "Shift" },
		{ KeyCode::KEY_ALT, "Alt" },
		{ KeyCode::KEY_CTRL, "Ctrl" },
		{ KeyCode::KEY_WIN, "Win" },
	};

	std::map<const MouseCode, std::string> Translator::MouseCodeDatabase_
	{
		{ MouseCode::MOUSE_NO_CODE, "NoCode" },
		{ MouseCode::MOUSE_LEFT, "LeftClick" },
		{ MouseCode::MOUSE_RIGHT, "RightClick" },
		{ MouseCode::MOUSE_MIDDLE, "MiddleClick" },
		{ MouseCode::MOUSE_WHEEL, "WheelMove" },
	};

	std::string Translator::translate(const KeyCode code) noexcept
	{
		return keyCodeDatabase_[code];
	}

	std::string Translator::translate(const MouseCode code) noexcept
	{
		return MouseCodeDatabase_[code];
	}
}