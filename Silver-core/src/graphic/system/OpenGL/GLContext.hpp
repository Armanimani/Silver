#pragma once

#include "graphic\context\Context.hpp"

namespace silver::core::graphic
{
	class GLContext : public Context
	{
	public:
		void create(void* deviceContext) override;
		void release() override;

		void* renderingContext() override { return renderingContext_; }

	private:
		static void* deviceContext_;
		static void* renderingContext_;
	};
}