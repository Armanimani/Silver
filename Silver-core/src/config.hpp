#pragma once

#define SILVER_DEBUG
#if defined(SILVER_DEBUG) || defined(_DEBUG)
	#define SILVER_LOGGER_ERROR
	#define SILVER_LOGGER_WARNING
	#define SILVER_LOGGER_INFORMATION
	#define SILVER_LOGGER_MESSAGE
	#define SILVER_LOGGER_ENGINE
	#define SILVER_LOGGER_LOG_TO_FILE 
#endif
