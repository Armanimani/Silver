#include <iostream>
#include "app\Application.hpp"

int main()
{
	silver::core::Settings settings;
	settings.appplication.updateFrequency = 0.005f;

	silver::core::Application game(settings);
	game.start();
}