#pragma once

#include <string>

#include "window\WindowSettings.hpp"

namespace silver::core
{
	class Application
	{
	public:
		Application(const std::string name, const WindowSettings windowSettings);
		~Application();

		void start();

	private:
		std::string name_;
		WindowSettings windowSettings_;

		void init_();
	};
}