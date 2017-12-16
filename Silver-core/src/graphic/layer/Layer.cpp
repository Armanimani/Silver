#include "graphic\layer\Layer.hpp"

namespace silver::core::graphic
{
	void Layer::set_renderable(const bool state) noexcept
	{
		renderable_ = state;
	}

	bool Layer::renderable() const noexcept
	{
		return renderable_;
	}

	void Layer::set_active(const bool state) noexcept
	{
		active_ = state;
	}

	bool Layer::active() const noexcept
	{
		return active_;
	}

	void Layer::set_handle(const unsigned int handle) noexcept
	{
		handle_ = handle;
	}

	unsigned int Layer::handle() const noexcept
	{
		return handle_;
	}
}