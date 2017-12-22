#pragma once

#include <memory>
#include <Windows.h>
#include <iostream>

#include "config.hpp"
#include "util\logger\logger_base.hpp"

namespace silver::core::impl
{
	class Logger_win32
	{
	public:
		static const Logger_win32& instance();
		
		Logger_win32();

		template <typename T>
		void log(T&& object) const noexcept;
		template <typename T>
		void log_error(T&& object) const noexcept;
		template <typename T>
		void log_warning(T&& object) const noexcept;
		template <typename T>
		void log_information(T&& object) const noexcept;
		template <typename T>
		void log_engine(T&& object) const noexcept;

	private:
		enum class LogLevelColor
		{
			error = 12,
			warning = 14,
			information = 10,
			message = 7,
			engine = 11,
		};

		static std::unique_ptr<Logger_win32> s_instance_;

		HANDLE handle_;

		std::string get_time_() const noexcept;
		template <typename T>
		void log_(T&& object, LogLevelColor levelColor) const noexcept;
	};

	template <typename T>
	void Logger_win32::log(T&& object) const noexcept
	{
		auto time = get_time_();
		std::cout << time + " " + toString(object) << std::endl;
	}

	template <typename T>
	void Logger_win32::log_error(T&& object) const noexcept
	{
		#ifdef SILVER_LOGGER_ERROR
		log_(std::forward<T>(object), LogLevelColor::error);
		#endif
	}

	template <typename T>
	void Logger_win32::log_warning(T&& object) const noexcept
	{
		#ifdef SILVER_LOGGER_WARNING
		log_(std::forward<T>(object), LogLevelColor::warning);
		#endif
	}

	template <typename T>
	void Logger_win32::log_information(T&& object) const noexcept
	{
		#ifdef SILVER_LOGGER_INFORMATION
		log_(std::forward<T>(object), LogLevelColor::information);
		#endif
	}

	template <typename T>
	void Logger_win32::log_engine(T&& object) const noexcept
	{
		#ifdef SILVER_LOGGER_ENGINE
		log_(std::forward<T>(object), LogLevelColor::engine);
		#endif
	}

	template <typename T>
	void Logger_win32::log_(T&& object, LogLevelColor levelColor) const noexcept
	{
		auto time = get_time_();
		auto message = toString(std::forward<T>(object));
		SetConsoleTextAttribute(handle_, static_cast<WORD>(levelColor));
		switch (levelColor)
		{
			case LogLevelColor::error:
			{
				std::cout << time + " ERROR: " + message << std::endl;
				break;
			}
			case LogLevelColor::warning:
			{
				std::cout << time + " WARNING: " + message << std::endl;
				break;
			}
			case LogLevelColor::information:
			{
				std::cout << time + " INFORMATION: " + message << std::endl;
				break;
			}
			case LogLevelColor::engine:
			{
				std::cout << time + " Engine: " + message << std::endl;
				break;
			}
			default:
			{
				std::cout << time + " " + message << std::endl;
				break;
			}
		}
		SetConsoleTextAttribute(handle_, static_cast<WORD>(LogLevelColor::message));

		#ifdef SILVER_LOGGER_LOG_TO_FILE
		// TODO
		#endif
	}
}