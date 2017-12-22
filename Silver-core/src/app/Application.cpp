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
#include "graphic\renderer\Renderer.hpp"

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
			Logger::instance().log_error("Unknown Fatal Error");
			throw;
		}
	}


	void Application::load_scene_(graphic::Scene* scene) noexcept
	{
		scene_ = scene;
	}

	Application::~Application() {}

	void Application::start()
	{
		running_ = true;
		paused_ = false;
		try
		{
			if (!initialized_)
			{
				system_init_();
			}
			init_();
			window_->show();
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
			Logger::instance().log_error("Unknown Fatal Error");
		}
	}

	void Application::pause() noexcept
	{
		paused_ = true;
	}

	void Application::resume() noexcept
	{
		paused_ = false;
	}

	void Application::stop() noexcept
	{
		running_ = false;
	}

	void Application::system_init_()
	{
		Logger::instance().log_engine("initializing...");

		window_->create();
		graphic::Renderer::init();
		initialized_ = true;
	}

	void Application::init_()
	{
		on_init_();
		scene_->on_init();
	}

	void Application::run_()
	{
		Logger::instance().log_engine("started...");

		float elapsedTime { 0.0f };
		uint updateCounter {};
		uint frameCounter {};

		clock_->reset();
		auto now = clock_->time();
		TimeStep updateTimeStep(now);
		TimeStep timeStep(now);

		while (running_)
		{
			window_->clear();

			auto now = clock_->time();
			if (updateTimeStep.deltaTime_s(now) >= settings_.updateFrequency && !paused_)
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
		if (!paused_)
		{
			scene_->on_update(dt_s);
		}
	}

	void Application::second_update_()
	{
		on_second_update_();
		scene_->on_second_update();
	}

	void Application::render_()
	{
		on_render_();
		scene_->on_render();
		graphic::Renderer::instance()->present();
	}

	uint Application::get_FPS_() const noexcept
	{
		return FPS_;
	}

	uint Application::get_UPS_() const noexcept
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
			scene_->on_keyboard_event(p.get());
		}
		else if (e->type() == event::Event_base::Type::MOUSE)
		{
			auto p = std::unique_ptr<event::MouseEvent>(static_cast<event::MouseEvent*>(e.release()));
			scene_->on_mouse_event(p.get());
		}
	}

	void Application::handle_window_event_(std::unique_ptr<event::WindowEvent>&& e)
	{
		switch (e->state())
		{
			case (event::WindowEvent::State::CREATE):
			{
				on_window_create_();
				scene_->on_window_create();
				break;
			}
			case (event::WindowEvent::State::CLOSE):
			{
				on_window_close_();
				scene_->on_window_close();
				break;
			}
			case (event::WindowEvent::State::DESTROY):
			{
				on_window_destroy_();
				scene_->on_window_destroy();
				break;
			}
			case (event::WindowEvent::State::FOCUS):
			{
				auto p = static_cast<event::WindowFocusEvent*>(e.release());
				on_window_focus_(p->state());
				scene_->on_window_focus(p->state());
				break;
			}
			case(event::WindowEvent::State::SHOW):
			{
				auto p = static_cast<event::WindowShowEvent*>(e.release());
				on_window_show_(p->state());
				scene_->on_window_show(p->state());
				break;
			}
			case(event::WindowEvent::State::RESIZE):
			{
				auto p = static_cast<event::WindowResizeEvent*>(e.release());
				on_window_resize_(p->size());
				scene_->on_window_resize(p->size());
				break;
			}
		}
	}
}