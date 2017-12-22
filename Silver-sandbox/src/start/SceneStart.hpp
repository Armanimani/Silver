#pragma once

#include "start/layers/TestLayer2D.hpp"
#include "start/layers/FPSLoggerLayer.hpp"
#include "graphic/scene/Scene.hpp"


class SceneStart : public silver::graphic::Scene
{
public:
	SceneStart();
	void update_FPS_UPS(const uint fps, const uint ups);

protected:
	std::unique_ptr<FPSLoggerLayer> fps_;
	std::unique_ptr<TestLayer2D> test_;
};