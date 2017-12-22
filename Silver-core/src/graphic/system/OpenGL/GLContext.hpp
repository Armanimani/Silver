#pragma once

#include "graphic\context\Context.hpp"

namespace silver::graphic
{
	class GLContext : public Context
	{
	public:
		void create(void* deviceContext) override;
		void release() override;

		void* renderingContext() override { return s_renderingContext_; }

		void swap_buffer() const noexcept override;
		void clear() const noexcept override;

	private:
		static void* s_renderingContext_;
	};
}