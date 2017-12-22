#include "SceneStart.hpp"

SceneStart::SceneStart()
{
	fps_ = std::make_unique<FPSLoggerLayer>();
	test_ = std::make_unique<TestLayer2D>();
	push_layer(fps_.get());
	push_layer(test_.get());
}

void SceneStart::update_FPS_UPS(const uint fps, const uint ups)
{
	fps_->update_values(fps, ups);
}