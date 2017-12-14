#pragma once

#include <string>
#include <optional>

#include "math\math.hpp"
#include "event\events.hpp"
#include "util\translator\Translator.hpp"

namespace silver::core::impl
{
	template <typename T>
	static std::string toString(T&& object)
	{
		return { object };
	}

	template <typename T>
	static std::string toString(const Vector2<T> vec)
	{
		return { "[ " + std::to_string(vec.x) + " , " + std::to_string(vec.y) + " ]" };
	}

	template<std::size_t N>
	static std::string toString(const char (&object)[N])
	{
		return { object };
	}

	static std::string toString(const int object)
	{
		return std::to_string(object);
	}

	static std::string toString(const unsigned int object)
	{
		return std::to_string(object);
	}

	static std::string toString(const float object)
	{
		return std::to_string(object);
	}

	static std::string toString(const double object)
	{
		return std::to_string(object);
	}

	static std::string toString(const bool object)
	{
		return (object) ? "TRUE" : "FALSE";
	}

	static std::string toString(const event::WindowResizeEvent object)
	{
		return { "Window -> Resize " + toString(object.size()) };
	}

	static std::string toString(const event::WindowFocusEvent object)
	{
		return { "Window -> Focus " + toString(object.state()) };
	}

	static std::string toString(const event::WindowCloseEvent object)
	{
		return { "Window -> Closed" };
	}

	static std::string toString(const event::WindowCreateEvent object)
	{
		return { "Window -> Created" };
	}

	static std::string toString(const event::WindowDestroyEvent object)
	{
		return { "Window -> Destoryed" };
	}

	static std::string toString(const event::WindowShowEvent object)
	{
		return { "Window -> Show " + toString(object.state()) };
	}

	static std::string toString(const event::KeyboardPressedEvent object)
	{
		auto key = Translator::translate(object.key());
		return { "Key -> Pressed " + key + " @ " + toString(object.position()) + " *alt = " + toString(object.alt()) + " *ctrl = " + toString(object.ctrl()) + " *shift = " + toString(object.shift()) + " *win = " + toString(object.win()) + " *wasDown = " + toString(object.was_down()) };
	}

	static std::string toString(const event::KeyboardReleasedEvent object)
	{
		auto key = Translator::translate(object.key());
		return { "Key -> Released " + key + " @ " + toString(object.position()) + " *alt = " + toString(object.alt()) + " *ctrl = " + toString(object.ctrl()) + " *shift = " + toString(object.shift()) + " *win = " + toString(object.win()) + " *wasDown = " + toString(object.was_down()) };
	}

	static std::string toString(const event::MouseMovedEvent object)
	{
		return { "Mouse -> Move " + toString(object.position()) + " *alt = " + toString(object.alt()) + " *ctrl = " + toString(object.ctrl()) + " *shift = " + toString(object.shift()) + " *win = " + toString(object.win())};
	}

	static std::string toString(const event::MousePressedEvent object)
	{
		auto key = Translator::translate(object.key());
		return { "Mouse -> Pressed " + key + " @ " +toString(object.position()) + " *alt = " + toString(object.alt()) + " *ctrl = " + toString(object.ctrl()) + " *shift = " + toString(object.shift()) + " *win = " + toString(object.win()) };
	}

	static std::string toString(const event::MouseReleasedEvent object)
	{
		auto key = Translator::translate(object.key());
		return { "Mouse -> Released " + key + " @ " + toString(object.position()) + " *alt = " + toString(object.alt()) + " *ctrl = " + toString(object.ctrl()) + " *shift = " + toString(object.shift()) + " *win = " + toString(object.win()) };
	}

	static std::string toString(const event::MouseWheelEvent object)
	{
		return { "Mouse -> Released " + std::to_string(object.value()) + " @ " + toString(object.position()) + " *alt = " + toString(object.alt()) + " *ctrl = " + toString(object.ctrl()) + " *shift = " + toString(object.shift()) + " *win = " + toString(object.win()) };
	}
}