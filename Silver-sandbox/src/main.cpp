#include <iostream>
#include "Game.hpp"

int main()
{
	silver::core::Settings settings;
	settings.appplication.updateFrequency = 0.005f;

	Game game(settings);
	game.start();
}