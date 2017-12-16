#include "app\Application.hpp"

#include <algorithm>

#include "common.hpp"
#include "exceptions\Exception.hpp"
#include "exceptions\CriticalException.hpp"
#include "util\logger\Logger.hpp"
#include "clock\TimeStep.hpp"
#include "input\InputManager.hpp"
#include "window\Window.hpp"
#include "clock\Clock.hpp"

namespace silver::core
{
	Application::Application(const Settings settings)
	{
		try
		{
			Logger::instance();
			InputManager::instance();
			InputManager::instance().set_event_callback(std::bind(&Application::handle_input_event_, this, std::placeholders::_1));

			settings_ = std::move(settings.appplication);
			clock_ = std::make_unique<Clock>();
			graphic::Context::init(settings_.renderingContext);
			window_ = std::make_unique<Window>(std::move(settings.window));
		}
		catch (...)
		{
			Logger::instance().log_error("Uknown Fatal Error");
			throw;
		}
	}

	Application::~Application() {}

	void Application::start()
	{
		try
		{
			init_();
			run_();
		}
		catch (const Exception<std::string>& e)
		{
			Logger::instance().log(e.get());
		}
		catch (const CriticalException& e)
		{
			Logger::instance().log_error(e.get());
		}
		catch (...)
		{
			Logger::instance().log_error("Uknown Fatal Error");
		}
	}

	unsigned int Application::push_layer_(graphic::Layer* layer) noexcept
	{
		layer->set_handle(layer_handle_);
		layers_.push_back(layer);
		layer_handle_++;
		return layer_handle_ - 1;
	}

	unsigned int Application::push_overlay_(graphic::Layer* layer) noexcept
	{
		layer->set_handle(overlay_handle_);
		overlays_.push_back(layer);
		overlay_handle_++;
		return overlay_handle_ - 1;
	}

	void Application::pop_layer_(unsigned int handle) noexcept
	{
		auto pos = std::find_if(layers_.begin(), layers_.end(), [handle] (const graphic::Layer* layer) { return layer->handle() == handle; });
		layers_.erase(pos);
	}

	void Application::pop_overlay_(unsigned int handle) noexcept
	{
		auto pos = std::find_if(overlays_.begin(), overlays_.end(), [handle] (const graphic::Layer* layer) { return layer->handle() == handle; });
		overlays_.erase(pos);
	}

	void Application::init_()
	{
		window_->create();

		on_init_();
		for (auto i = layers_.begin(); i != layers_.end(); ++i)
		{
			(*i)->on_init();
		}

		for (auto i = overlays_.begin(); i != overlays_.end(); ++i)
		{
			(*i)->on_init();
		}
	}

	void Application::run_()
	{
		Logger::instance().log_information("Engine started...");

		window_->show();

		float elapsedTime { 0.0f };
		unsigned int updateCounter {};
		unsigned int frameCounter {};

		clock_->reset();
		auto now = clock_->time();
		TimeStep updateTimeStep(now);
		TimeStep timeStep(now);

		while (running_)
		{
			auto now = clock_->time();
			if (updateTimeStep.deltaTime_s(now) >= settings_.updateFrequency)
			{
				update_(updateTimeStep.deltaTime_s(now));
				updateTimeStep.update(now);
				updateCounter++;
			}

			render_();
			frameCounter++;

			if (timeStep.deltaTime_s(now) >= 1.0f)
			{
				elapsedTime += timeStep.deltaTime_s();
				timeStep.update(now);

				FPS_ = frameCounter;
				UPS_ = updateCounter;
				frameCounter = 0;
				updateCounter = 0;

				second_update_();
			}
		}
	}

	void Application::update_(const float dt_s)
	{
		window_->update();
		InputManager::instance().update();
		
		on_update_();
		for (auto i = layers_.begin(); i != layers_.end(); ++i)
		{
			(*i)->on_update(dt_s);
		}

		for (auto i = overlays_.begin(); i != overlays_.end(); ++i)
		{
			(*i)->on_update(dt_s);
		}
	}

	void Application::second_update_()
	{
		on_second_update_();
		for (auto i = layers_.begin(); i != layers_.end(); ++i)
		{
			(*i)->on_second_update();
		}

		for (auto i = overlays_.begin(); i != overlays_.end(); ++i)
		{
			(*i)->on_second_update();
		}
	}

	void Application::render_()
	{
		on_render_();
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

	unsigned int Application::get_FPS_() const noexcept
	{
		return FPS_;
	}

	unsigned int Application::get_UPS_() const noexcept
	{
		return UPS_;
	}

	void Application::handle_input_event_(std::unique_ptr<event::Event_base>&& e)
	{
		if (e->type() == event::Event_base::Type::WINDOW)
		{
			auto p = std::unique_ptr<event::WindowEvent>(static_cast<event::WindowEvent*>(e.release()));
			handle_window_event_(std::move(p));
		}
		else if (e->type() == event::Event_base::Type::KEYBOARD)
		{
			auto p = std::unique_ptr<event::KeyboardEvent>(static_cast<event::KeyboardEvent*>(e.release()));
			for (auto i = layers_.begin(); i != layers_.end(); ++i)
			{
				(*i)->on_keyboard_event(std::move(p));
			}

			for (auto i = overlays_.begin(); i != overlays_.end(); ++i)
			{
				(*i)->on_keyboard_event(std::move(p));
			}
		}
		else if (e->type() == event::Event_base::Type::MOUSE)
		{
			auto p = std::unique_ptr<event::MouseEvent>(static_cast<event::MouseEvent*>(e.release()));
			for (auto i = layers_.begin(); i != layers_.end(); ++i)
			{
				(*i)->on_mouse_event(std::move(p));
			}

			for (auto i = overlays_.begin(); i != overlays_.end(); ++i)
			{
				(*i)->on_mouse_event(std::move(p));
			}
		}
	}

	void Application::handle_window_event_(std::unique_ptr<event::WindowEvent>&& e)
	{
		switch (e->state())
		{
			case (event::WindowEvent::State::CREATE):
			{
				for (auto i = layers_.begin(); i != layers_.end(); ++i)
				{
					(*i)->on_window_create();
				}

				for (auto i = overlays_.begin(); i != overlays_.end(); ++i)
				{
					(*i)->on_window_create();
				}
				break;
			}
			case (event::WindowEvent::State::CLOSE):
			{
				for (auto i = layers_.begin(); i != layers_.end(); ++i)
				{
					(*i)->on_window_close();
				}

				for (auto i = overlays_.begin(); i != overlays_.end(); ++i)
				{
					(*i)->on_window_close();
				}
				break;
			}
			case (event::WindowEvent::State::DESTROY):
			{
				for (auto i = layers_.begin(); i != layers_.end(); ++i)
				{
					(*i)->on_window_destroy();
				}

				for (auto i = overlays_.begin(); i != overlays_.end(); ++i)
				{
					(*i)->on_window_destroy();
				}
				break;
			}
			case (event::WindowEvent::State::FOCUS):
			{
				auto p = static_cast<event::WindowFocusEvent*>(e.release());
				for (auto i = layers_.begin(); i != layers_.end(); ++i)
				{
					(*i)->on_window_focus(p->state());
				}

				for (auto i = overlays_.begin(); i != overlays_.end(); ++i)
				{
					(*i)->on_window_focus(p->state());
				}
				break;
			}
			case(event::WindowEvent::State::SHOW):
			{
				auto p = static_cast<event::WindowShowEvent*>(e.release());
				for (auto i = layers_.begin(); i != layers_.end(); ++i)
				{
					(*i)->on_window_show(p->state());
				}

				for (auto i = overlays_.begin(); i != overlays_.end(); ++i)
				{
					(*i)->on_window_show(p->state());
				}
				break;
			}
			case(event::WindowEvent::State::RESIZE):
			{
				auto p = static_cast<event::WindowResizeEvent*>(e.release());
				for (auto i = layers_.begin(); i != layers_.end(); ++i)
				{
					(*i)->on_window_resize(p->size());
				}

				for (auto i = overlays_.begin(); i != overlays_.end(); ++i)
				{
					(*i)->on_window_resize(p->size());
				}
				break;
			}
		}
	}
}