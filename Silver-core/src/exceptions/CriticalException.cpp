#include "exceptions\CriticalException.hpp"

namespace silver::core
{
	std::string CriticalException::get() const
	{
		return std::string("@ " + file_ + ':' + std::to_string(line_) + " -> " + message_);
	}
}