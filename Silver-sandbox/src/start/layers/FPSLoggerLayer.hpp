#pragma once

#include "graphic/scene/layer/console/LoggerLayer.hpp"

class FPSLoggerLayer : public silver::graphic::LoggerLayer
{
public:
	void on_second_update() noexcept override
	{
		if (active_)
		{
			std::string log { "FPS = " + std::to_string(FPS_) + "     " + "UPS = " + std::to_string(UPS_) };
			logger_->log(log);
		}
	}

	void on_keyboard_event(silver::core::event::KeyboardEvent* e) noexcept
	{
		if (e->key() == silver::core::KeyCode::KEY_F && e->state() == silver::core::event::KeyboardEvent::State::PRESSED &&  e->alt() && e->ctrl())
		{
			if (active_ == true)
			{
				active_ = false;
			}
			else
			{
				active_ = true;
			}
		}
	}

	void update_values(const unsigned int fps, const unsigned int ups)
	{
		FPS_ = fps;
		UPS_ = ups;
	}

private:
	bool active_ = true;
	unsigned int FPS_;
	unsigned int UPS_;
};