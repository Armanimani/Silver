#include "util\logger\platform\Logger_win32.hpp"

namespace silver::core::impl
{
	Logger_win32::Logger_win32()
	{
		handle_ = GetStdHandle(STD_OUTPUT_HANDLE);
		file_.open("silver.log");
	}

	std::unique_ptr<Logger_win32> Logger_win32::instance_;
	const Logger_win32& Logger_win32::instance()
	{
		if (!instance_) instance_ = std::make_unique<Logger_win32>();
		return *instance_;
	}

	std::string Logger_win32::get_time_() const noexcept
	{
		SYSTEMTIME time;
		GetSystemTime(&time);
		return { '[' + std::to_string(time.wHour) + ':' + std::to_string(time.wMinute) + ':' + std::to_string(time.wSecond) + ']' };
	}
}