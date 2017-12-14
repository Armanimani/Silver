#include "event\Event_base.hpp"

#include <memory>

namespace silver::core::event
{
	Event_base::Event_base(const Type type) : type_(std::move(type)) {}

	Event_base::Type Event_base::type() const noexcept
	{
		return type_;
	}
}