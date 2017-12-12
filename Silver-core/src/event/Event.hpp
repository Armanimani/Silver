#pragma once

namespace silver::core
{
	class Event
	{
	public:
		enum class Type
		{
			keyboard,
			mouse,
			window
		};

		Type get_type() const noexcept;

	protected:
		Event(const Type type);

		Type type_;
	};
}