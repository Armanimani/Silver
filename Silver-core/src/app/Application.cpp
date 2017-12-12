#include "app\Application.hpp"

#include "common.hpp"
#include "exceptions\Exception.hpp"
#include "exceptions\CriticalException.hpp"
#include "util\logger\Logger.hpp"
#include "clock\TimeStep.hpp"

#include "window\Window.hpp"
#include "clock\Clock.hpp"

namespace silver::core
{
	Application::Application(const Settings settings)
	{
		try
		{
			Logger::instance();
			settings_ = std::move(settings.appplication);
			clock_ = std::make_unique<Clock>();
			window_ = std::make_unique<Window>(std::move(settings.window));
			context_ = std::make_unique<graphic::Context>(settings_.renderingContext);
		}
		catch (...)
		{
			Logger::instance().log_error("Uknown Fatal Error");
			throw;
		}
	}

	Application::~Application()
	{
	}

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

	void Application::init_()
	{
		window_->create();
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
				updateTimeStep.update(now);
				updateCounter++;
			}

			window_->update();

			frameCounter++;

			if (timeStep.deltaTime_s(now) >= 1.0f)
			{
				elapsedTime += timeStep.deltaTime_s();
				timeStep.update(now);

				std::string log { "FPS = " + std::to_string(frameCounter) + "     " + "UPS = " + std::to_string(updateCounter) + "     " + "elapsed = " + std::to_string(elapsedTime) };
				Logger::instance().log(log);

				frameCounter = 0;
				updateCounter = 0;
			}
		}
	}
}