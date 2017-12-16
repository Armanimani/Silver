#include "platform\windows\Logger_win32.hpp"

namespace silver::core::impl
{
	std::unique_ptr<Logger_win32> Logger_win32::s_instance_;
	const Logger_win32& Logger_win32::instance()
	{
		if (!s_instance_) s_instance_ = std::make_unique<Logger_win32>();
		return *s_instance_;
	}

	Logger_win32::Logger_win32()
	{
		handle_ = GetStdHandle(STD_OUTPUT_HANDLE);
	}

	std::string Logger_win32::get_time_() const noexcept
	{
		SYSTEMTIME time;
		GetSystemTime(&time);
		return { '[' + std::to_string(time.wHour) + ':' + std::to_string(time.wMinute) + ':' + std::to_string(time.wSecond) + ']' };
	}
}