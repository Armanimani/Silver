#include "graphic\scene\layer\Layer.hpp"

namespace silver::graphic
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

	void Layer::set_handle(const uint handle) noexcept
	{
		handle_ = handle;
	}

	uint Layer::handle() const noexcept
	{
		return handle_;
	}
}