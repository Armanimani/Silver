#pragma once

#include "graphic\buffer\VertexArray.hpp"

namespace silver::graphic
{
	class GLVertexArray : public VertexArray
	{
	public:
		GLVertexArray();
		~GLVertexArray();

		void bind() const noexcept override;
		void unbind() const noexcept override;
	};
}