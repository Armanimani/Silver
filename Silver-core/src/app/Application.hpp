#pragma once

#include <string>

#include "clock\Clock.hpp"
#include "settings\Settings.hpp"

namespace silver::core
{
	class Application
	{
	public:
		Application(const Settings settings);
		~Application();

		void start();

	private:
		Clock clock_;

		std::string name_;
		ApplicationSettings settings_;

		bool running_ { true };

		void init_();
		void run_();
	};
}