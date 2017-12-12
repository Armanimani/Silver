#pragma once

#include "graphic\system\RenderingContext.hpp"

namespace silver::core::graphic
{
	class Context
	{
	public:
		Context();
		Context(const RenderingContext& conext);

		void* renderingContext();

		void create(void* deviceContext);
		void release();

	protected:
		static RenderingContext API_;
	};
}