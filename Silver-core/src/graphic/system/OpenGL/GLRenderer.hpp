#pragma once

#include "graphic\renderer\Renderer.hpp"

namespace silver::graphic
{
	class GLRenderer : public Renderer
	{
	public:

	private:
		void init_internal() const noexcept override;
		void present_internal() const noexcept override;
		void set_viewport_internal(const vec2ui& position, const vec2ui& size) const noexcept override;
		void set_depth_test_internal(const bool state = true) const noexcept override;
		void clear_buffer_internal(const RendererBuffer buffer) const noexcept override;

		void log_version_() const noexcept;
	};
}