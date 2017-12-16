#pragma once

#include <string>
#include <memory>
#include <vector>

#include "settings\Settings.hpp"
#include "window\Window_API.hpp"
#include "clock\Clock_API.hpp"
#include "event\events.hpp"
#include "graphic\layer\Layer.hpp"

namespace silver::core
{
	class Application
	{
	public:
		Application(const Settings settings);
		~Application();

		void start();

	protected:
		unsigned int push_layer_(graphic::Layer* layer) noexcept;
		unsigned int push_overlay_(graphic::Layer* layer) noexcept;
		void pop_layer_(unsigned int handle) noexcept;
		void pop_overlay_(unsigned int handle) noexcept;

		virtual void on_init_() noexcept {}
		virtual void on_update_() noexcept {}
		virtual void on_render_() noexcept {}
		virtual void on_second_update_() noexcept {}

		unsigned int get_FPS_() const noexcept;
		unsigned int get_UPS_() const noexcept;

	private:
		ApplicationSettings settings_;
		std::unique_ptr<Clock_API> clock_;
		std::unique_ptr<Window_API> window_;

		unsigned int layer_handle_ {};
		unsigned int overlay_handle_ {};
		std::vector<graphic::Layer*> layers_;
		std::vector<graphic::Layer*> overlays_;

		unsigned int FPS_ {};
		unsigned int UPS_ {};

		bool running_ { true };

		void init_();
		void run_();
		void update_(const float dt_s);
		void second_update_();
		void render_();

		void handle_input_event_(std::unique_ptr<event::Event_base>&& e);
		void handle_window_event_(std::unique_ptr<event::WindowEvent>&& e);
	};
}