#include "app\Application.hpp"

#include "exceptions\Exception.hpp"
#include "util\logger\Logger.hpp"

#include "common.hpp"

namespace silver::core
{
	Application::Application(const std::string name, const WindowSettings windowSettings) : name_(std::move(name)), windowSettings_(std::move(windowSettings))
	{
	}

	Application::~Application()
	{
	}

	void Application::start()
	{
		try
		{
			init_();
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
}