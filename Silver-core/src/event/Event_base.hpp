#pragma once

namespace silver::core::event
{
	class Event_base
	{
	public:
		enum class Type
		{
			KEYBOARD,
			MOUSE,
			WINDOW,
			ENGINE
		};

		Type type() const noexcept;

	protected:
		Event_base(const Type type);

		const Type type_;
	};
}