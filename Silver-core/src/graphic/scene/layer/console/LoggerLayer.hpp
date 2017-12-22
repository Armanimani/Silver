#pragma once

#include "graphic\scene\layer\Layer.hpp"
#include "util\logger\Logger.hpp"

namespace silver::graphic
{
	class LoggerLayer : public Layer
	{
	public:
		LoggerLayer();

	protected:
		const core::Logger* logger_;
	};
}