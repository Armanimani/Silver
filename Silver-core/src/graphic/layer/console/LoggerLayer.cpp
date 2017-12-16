#include "graphic\layer\console\LoggerLayer.hpp"

namespace silver::core::graphic
{
	LoggerLayer::LoggerLayer() : logger_(&Logger::instance()) {}
}