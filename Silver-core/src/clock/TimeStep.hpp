#pragma once

#include <memory>

namespace silver::core
{
	class TimeStep
	{
	public:
		TimeStep(const float initialTime) : initialTime_(std::move(initialTime)) {}

		void update(const float currentTime)
		{
			deltaTime_ = currentTime - initialTime_;
			initialTime_ = currentTime;
		}

		float deltaTime_ms() { return deltaTime_ * 1000; }
		float deltaTime_s() { return deltaTime_; }
		float deltaTime_m() { return deltaTime_ / 60; }

		float deltaTime_ms(const float& now) { return (now - initialTime_) * 1000; }
		float deltaTime_s(const float& now) { return now - initialTime_; }
		float deltaTime_m(const float& now) { return (now - initialTime_) / 60; }

	private:
		float initialTime_;
		float deltaTime_ {};
	};
}