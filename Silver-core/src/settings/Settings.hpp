#pragma once

#include "settings\WindowSettings.hpp"
#include "settings\ApplicationSettings.hpp"

namespace silver::core
{
	struct Settings
	{
		WindowSettings window;
		ApplicationSettings appplication;
	};
}