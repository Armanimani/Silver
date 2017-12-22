#pragma once

#include <memory>

#include "common.hpp"
#include "graphic\context\Context.hpp"

namespace silver::graphic
{
	enum class RendererBuffer
	{
		DEPTH_BUFFER,
		COLOR_BUFFER,
	};

	class Renderer
	{
	public:
		static Renderer * instance() noexcept;
		static void init();
		static void present() noexcept;
		static void set_viewport(const vec2ui& position, const vec2ui& size) noexcept;
		static void set_depth_test(const bool state = true) noexcept;
		static void clear_buffer(const RendererBuffer buffer) noexcept;

	protected:
		virtual void init_internal() const noexcept = 0;
		virtual void present_internal() const noexcept = 0;
		virtual void set_viewport_internal(const vec2ui& position, const vec2ui& size) const noexcept = 0;
		virtual void set_depth_test_internal(const bool state = true) const noexcept = 0;
		virtual void clear_buffer_internal(const RendererBuffer buffer) const noexcept = 0;

	private:
		static std::unique_ptr<Renderer> s_instance_;
	};
}