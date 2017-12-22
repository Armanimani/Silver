#include "graphic/scene/Scene.hpp"

#include <algorithm>

namespace silver::graphic
{
	uint Scene::push_layer(graphic::Layer* layer) noexcept
	{
		layer->set_handle(layerHandle_);
		layers_.push_back(layer);
		layerHandle_++;
		return layerHandle_ - 1;
	}

	uint Scene::push_overlay(graphic::Layer* layer) noexcept
	{
		layer->set_handle(overlayHandle_);
		overlays_.push_back(layer);
		overlayHandle_++;
		return overlayHandle_ - 1;
	}

	void Scene::pop_layer(uint handle) noexcept
	{
		auto pos = std::find_if(layers_.begin(), layers_.end(), [handle] (const graphic::Layer* layer) { return layer->handle() == handle; });
		layers_.erase(pos);
	}

	void Scene::pop_overlay(uint handle) noexcept
	{
		auto pos = std::find_if(overlays_.begin(), overlays_.end(), [handle] (const graphic::Layer* layer) { return layer->handle() == handle; });
		overlays_.erase(pos);
	}

	Layer* Scene::get_layer(const uint id) const noexcept
	{
		return layers_[id];
	}

	Layer* Scene::get_overlay(const uint id) const noexcept
	{
		return overlays_[id];
	}

	void Scene::on_init() noexcept
	{
		for (auto i = layers_.begin(); i != layers_.end(); ++i)
		{
			(*i)->on_init();
		}

		for (auto i = overlays_.begin(); i != overlays_.end(); ++i)
		{
			(*i)->on_init();
		}
	}

	void Scene::on_update(const float dt_s) noexcept
	{
		for (auto i = layers_.begin(); i != layers_.end(); ++i)
		{
			(*i)->on_update(dt_s);
		}

		for (auto i = overlays_.begin(); i != overlays_.end(); ++i)
		{
			(*i)->on_update(dt_s);
		}
	}

	void Scene::on_second_update() noexcept
	{
		for (auto i = layers_.begin(); i != layers_.end(); ++i)
		{
			(*i)->on_second_update();
		}

		for (auto i = overlays_.begin(); i != overlays_.end(); ++i)
		{
			(*i)->on_second_update();
		}
	}

	void Scene::on_render() noexcept
	{
		for (auto i = layers_.begin(); i != layers_.end(); ++i)
		{
			if ((*i)->renderable())
				(*i)->on_render();
		}

		for (auto i = overlays_.begin(); i != overlays_.end(); ++i)
		{
			if ((*i)->renderable())
				(*i)->on_render();
		}
	}

	void Scene::on_keyboard_event(core::event::KeyboardEvent* e)
	{
		for (auto i = layers_.begin(); i != layers_.end(); ++i)
		{
			(*i)->on_keyboard_event(e);
		}

		for (auto i = overlays_.begin(); i != overlays_.end(); ++i)
		{
			(*i)->on_keyboard_event(e);
		}
	}

	void Scene::on_mouse_event(core::event::MouseEvent* e)
	{
		for (auto i = layers_.begin(); i != layers_.end(); ++i)
		{
			(*i)->on_mouse_event(e);
		}

		for (auto i = overlays_.begin(); i != overlays_.end(); ++i)
		{
			(*i)->on_mouse_event(e);
		}
	}

	void Scene::on_window_create()
	{
		for (auto i = layers_.begin(); i != layers_.end(); ++i)
		{
			(*i)->on_window_create();
		}

		for (auto i = overlays_.begin(); i != overlays_.end(); ++i)
		{
			(*i)->on_window_create();
		}
	}

	void Scene::on_window_close()
	{
		for (auto i = layers_.begin(); i != layers_.end(); ++i)
		{
			(*i)->on_window_close();
		}

		for (auto i = overlays_.begin(); i != overlays_.end(); ++i)
		{
			(*i)->on_window_close();
		}
	}

	void Scene::on_window_destroy()
	{
		for (auto i = layers_.begin(); i != layers_.end(); ++i)
		{
			(*i)->on_window_destroy();
		}

		for (auto i = overlays_.begin(); i != overlays_.end(); ++i)
		{
			(*i)->on_window_destroy();
		}
	}

	void Scene::on_window_resize(const vec2ui size)
	{
		for (auto i = layers_.begin(); i != layers_.end(); ++i)
		{
			(*i)->on_window_resize(size);
		}

		for (auto i = overlays_.begin(); i != overlays_.end(); ++i)
		{
			(*i)->on_window_resize(size);
		}
	}

	void Scene::on_window_focus(const bool state) noexcept
	{
		for (auto i = layers_.begin(); i != layers_.end(); ++i)
		{
			(*i)->on_window_focus(state);
		}

		for (auto i = overlays_.begin(); i != overlays_.end(); ++i)
		{
			(*i)->on_window_focus(state);
		}
	}

	void Scene::on_window_show(const bool state)
	{
		for (auto i = layers_.begin(); i != layers_.end(); ++i)
		{
			(*i)->on_window_show(state);
		}

		for (auto i = overlays_.begin(); i != overlays_.end(); ++i)
		{
			(*i)->on_window_show(state);
		}
	}

}