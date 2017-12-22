#pragma once

#include <memory>

#include "app\Application.hpp"
#include "event\events.hpp"
#include "start\SceneStart.hpp"



class Game : public silver::core::Application
{
public:
	Game(const silver::core::Settings settings) : Application(settings) {}

private:
	std::unique_ptr<SceneStart> startScene_;

	void on_init_() noexcept override;
	void on_second_update_() noexcept override;

	void on_window_close_() noexcept override;
};