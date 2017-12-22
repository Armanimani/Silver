#include "graphic\scene\layer\console\LoggerLayer.hpp"

namespace silver::graphic
{
	LoggerLayer::LoggerLayer() : logger_(&core::Logger::instance()) {}
}