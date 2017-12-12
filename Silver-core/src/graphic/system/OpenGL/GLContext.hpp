#pragma once

namespace silver::core::graphic
{
	class GLContext
	{
	public:
		static void create(void* deviceContext);
		static void release();

		static void* renderingContext() { return renderingContext_; }

	private:
		static void* deviceContext_;
		static void* renderingContext_;
	};
}