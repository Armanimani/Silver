#pragma once

#ifdef _WIN32
	#define __FILENAME__ (strrchr(__FILE__, '\\') ? strrchr(__FILE__, '\\') + 1 : __FILE__)
#else
	#define __FILENAME__ (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__)
#endif
#define SILVER_EXCEPTION(TYPE, OBJECT) Exception<TYPE>(std::string(__FILENAME__), __LINE__, OBJECT)