#pragma once

#include <memory>

#include "graphic\context\RenderingContext.hpp"

namespace silver::core::graphic
{
	class Context
	{
	public:
		static Context* instance();
		static void init(const RenderingContext& conext);

		virtual void* renderingContext() = 0;

		virtual void create(void* deviceContext) = 0;
		virtual void release() = 0;

	protected:
		static std::unique_ptr<Context> s_instance_;
	};
}