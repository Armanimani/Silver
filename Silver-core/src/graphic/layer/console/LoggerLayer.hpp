#pragma once

#include "graphic\layer\Layer.hpp"
#include "util\logger\Logger.hpp"

namespace silver::core::graphic
{
	class LoggerLayer : public Layer
	{
	public:
		LoggerLayer();

	protected:
		const Logger* logger_;
	};
}