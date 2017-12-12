#include "event\Event.hpp"

#include <memory>

namespace silver::core
{
	Event::Event(const Type type) : type_(std::move(type))
	{
	}

	Event::Type Event::get_type() const noexcept
	{
		return type_;
	}
}