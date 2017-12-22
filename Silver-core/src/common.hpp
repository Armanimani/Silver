#pragma once

#include "types.hpp"
#include "exceptions\Exception.hpp"
#include "exceptions\CriticalException.hpp"

#ifdef _WIN32
	#define __FILENAME__ (strrchr(__FILE__, '\\') ? strrchr(__FILE__, '\\') + 1 : __FILE__)
#else
	#define __FILENAME__ (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__)
#endif

#define SILVER_EXCEPTION(TYPE, OBJECT) silver::core::Exception<TYPE>(std::string(__FILENAME__), __LINE__, OBJECT)
#define SILVER_EXCEPTION_STRING(OBJECT) SILVER_EXCEPTION(std::string, std::string(OBJECT))
#define SILVER_EXCEPTION_CRITICAL(MESSAGE) silver::core::CriticalException(std::string(__FILENAME__), __LINE__, MESSAGE)