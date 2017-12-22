#pragma once

#include <string>
#include <memory>
#include <vector>

#include "settings\Settings.hpp"
#include "window\Window_API.hpp"
#include "clock\Clock_API.hpp"
#include "event\events.hpp"
#include "graphic\scene\Scene.hpp"
#include "common.hpp"

namespace silver::core
{
	class Application
	{
	public:
		Application(const Settings settings);
		~Application();

		void start();
		void pause() noexcept;
		void resume() noexcept;
		void stop() noexcept;

	protected:
		void load_scene_(graphic::Scene* scene) noexcept;

		virtual void on_init_() noexcept {}
		virtual void on_update_() noexcept {}
		virtual void on_render_() noexcept {}
		virtual void on_second_update_() noexcept {}

		virtual void on_window_create_() {}
		virtual void on_window_close_() {}
		virtual void on_window_destroy_() {}
		virtual void on_window_resize_(const vec2ui size) {}
		virtual void on_window_focus_(const bool state) noexcept {};
		virtual void on_window_show_(const bool state) {}

		uint get_FPS_() const noexcept;
		uint get_UPS_() const noexcept;

	private:
		ApplicationSettings settings_;
		std::unique_ptr<Clock_API> clock_;
		std::unique_ptr<Window_API> window_;
		graphic::Scene* scene_;

		std::vector<event::EngineEvent> engineEvents_;

		uint FPS_ {};
		uint UPS_ {};

		bool initialized_ { false };
		bool running_ { true };
		bool paused_ { false };

		void system_init_();
		void init_();
		void run_();
		void update_(const float dt_s);
		void second_update_();
		void render_();

		void handle_input_event_(std::unique_ptr<event::Event_base>&& e);
		void handle_window_event_(std::unique_ptr<event::WindowEvent>&& e);
	};
}