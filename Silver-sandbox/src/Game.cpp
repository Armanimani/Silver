#include "Game.hpp"

#include "util\logger\Logger.hpp"
#include "input\InputManager.hpp"

void Game::on_init_() noexcept
{

	startScene_ = std::make_unique<SceneStart>();
	load_scene_(startScene_.get());
}

void Game::on_second_update_() noexcept
{
	startScene_->update_FPS_UPS(get_FPS_(), get_UPS_());
}

void Game::on_window_close_() noexcept
{
	stop();
}