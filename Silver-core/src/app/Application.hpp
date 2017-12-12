#pragma once

#include <string>
#include <memory>

#include "settings\Settings.hpp"
#include "window\Window_API.hpp"
#include "clock\Clock_API.hpp"
#include "graphic\system\Context.hpp"

namespace silver::core
{
	class Application
	{
	public:
		Application(const Settings settings);
		~Application();

		void start();

	private:
		std::unique_ptr<Clock_API> clock_;
		std::unique_ptr<Window_API> window_;
		std::unique_ptr<graphic::Context> context_;

		ApplicationSettings settings_;

		bool running_ { true };

		void init_();
		void run_();
	};
}