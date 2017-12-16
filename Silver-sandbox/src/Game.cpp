#include "Game.hpp"

#include "util\logger\Logger.hpp"
#include "input\InputManager.hpp"

void Game::on_init_() noexcept
{
	fpsLayer_ = std::make_unique<FPSLoggerLayer>();
	push_layer_(fpsLayer_.get());
}

void Game::on_second_update_() noexcept
{
	fpsLayer_->update_values(get_FPS_(), get_UPS_());
}