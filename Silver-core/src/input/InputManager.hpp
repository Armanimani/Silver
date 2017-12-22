#pragma once

#include <array>
#include <functional>

#include "input\KeyCode.hpp"
#include "input\MouseCode.hpp"
#include "common.hpp"
#include "event\events.hpp"

namespace silver::core
{
	constexpr int32 MAX_KEYS = 512;
	constexpr int32 MAX_MOUSE_KEYS = 10;

	class InputManager
	{
	public:
		using EventCallback_t = std::function<void(std::unique_ptr<event::Event_base>&&)>;

		static InputManager& instance();

		InputManager();

		void update() noexcept;
		void clear() noexcept;

		static void catch_mouseEvent(std::unique_ptr<event::MouseEvent>&& e) noexcept;
		static void catch_keyboardEvent(std::unique_ptr<event::KeyboardEvent>&& e) noexcept;
		static void catch_windowEvent(std::unique_ptr<event::WindowEvent>&& e) noexcept;

		void set_event_callback(EventCallback_t func);

		bool is_key_pressed(const KeyCode code) const noexcept;
		bool is_key_released(const KeyCode code) const noexcept;
		bool is_key_held(const KeyCode code) const noexcept;
		bool was_key_pressed(const KeyCode code) const noexcept;

		bool is_mouse_pressed(const MouseCode code) const noexcept;
		bool is_mouse_released(const MouseCode code) const noexcept;
		bool is_mouse_held(const MouseCode code) const noexcept;
		bool was_mouse_pressed(const MouseCode code) const noexcept;

		vec2ui mouse_position() const noexcept;
		uint mouse_wheel() const noexcept;

	private:
		static std::unique_ptr<InputManager> s_instance_;
		EventCallback_t eventCallback_;

		std::array<bool, MAX_KEYS> keyState_ {};
		std::array<bool, MAX_KEYS> lastKeyState_ {};

		std::array<bool, MAX_MOUSE_KEYS> mouseState_ {};
		std::array<bool, MAX_MOUSE_KEYS> lastMouseState_ {};

		vec2ui mousePosition_ {};
		uint mouseWheelValue_ {};
	};
}