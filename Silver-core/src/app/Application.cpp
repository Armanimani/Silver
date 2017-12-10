#include "app\Application.hpp"

#include "exceptions\Exception.hpp"
#include "util\logger\Logger.hpp"
#include "clock\TimeStep.hpp"

#include "common.hpp"

namespace silver::core
{
	Application::Application(const Settings settings)
	{
		settings_ = std::move(settings.appplication);
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
		catch (...)
		{
			Logger::instance().log_error("Uknown Fatal Error");
		}
	}

	void Application::init_()
	{
		Logger::instance();
	}

	void Application::run_()
	{
		float elapsedTime { 0.0f };
		unsigned int updateCounter {};
		unsigned int frameCounter {};

		clock_.reset();
		auto now = clock_.time();
		TimeStep updateTimeStep(now);
		TimeStep timeStep(now);

		while (running_)
		{
			auto now = clock_.time();

			if (updateTimeStep.deltaTime_s(now) >= settings_.updateFrequency)
			{
				updateTimeStep.update(now);
				updateCounter++;
			}

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