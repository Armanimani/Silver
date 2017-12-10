#include <iostream>
#include "app\Application.hpp"

int main()
{
	silver::core::Application game("sandbox game", silver::core::WindowSettings());
	game.start();
}