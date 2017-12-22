#pragma once

#include <vector>
#include "graphic/scene/layer/Layer.hpp"

namespace silver::graphic
{
	class Scene
	{
	public:
		uint push_layer(graphic::Layer* layer) noexcept;
		uint push_overlay(graphic::Layer* layer) noexcept;
		void pop_layer(uint handle) noexcept;
		void pop_overlay(uint handle) noexcept;
		Layer* get_layer(const uint id) const noexcept;
		Layer* get_overlay(const uint id) const noexcept;

		void on_init() noexcept;
		void on_update(const float dt_s) noexcept;
		void on_second_update() noexcept;
		void on_render() noexcept;

		void on_keyboard_event(core::event::KeyboardEvent* e);
		void on_mouse_event(core::event::MouseEvent* e);
		void on_window_create();
		void on_window_close();
		void on_window_destroy();
		void on_window_resize(const vec2ui size);
		void on_window_focus(const bool state) noexcept;
		void on_window_show(const bool state);

	private:
		std::vector<graphic::Layer*> layers_;
		std::vector<graphic::Layer*> overlays_;

		uint layerHandle_;
		uint overlayHandle_;
	};
}