#include "window\Window_API.hpp"

namespace silver::core
{
	unsigned int Window_API::width() const noexcept
	{
		return settings_.width;
	}

	unsigned int Window_API::height() const noexcept
	{
		return settings_.height;
	}

	std::string Window_API::title() const noexcept
	{
		return settings_.title;
	}

	bool Window_API::is_focus() const noexcept
	{
		return settings_.focus;
	}

	bool Window_API::is_fullScreen() const noexcept
	{
		return settings_.fullScreen;
	}
}