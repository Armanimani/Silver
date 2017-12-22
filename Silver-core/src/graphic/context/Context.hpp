#pragma once

#include <memory>

namespace silver::graphic
{
	enum class RenderingContext_API
	{
		OpenGL,
		DirectX
	};

	class Context
	{
	public:
		static Context* instance();
		static void init(const RenderingContext_API& conext);
		static RenderingContext_API API() noexcept;

		virtual void* renderingContext() = 0;

		virtual void create(void* deviceContext) = 0;
		virtual void release() = 0;

		virtual void swap_buffer() const noexcept = 0;
		virtual void clear() const noexcept = 0;

	protected:
		static std::unique_ptr<Context> s_instance_;

		static RenderingContext_API s_renderingAPI_;
		static void* s_deviceContext_;
	};
}