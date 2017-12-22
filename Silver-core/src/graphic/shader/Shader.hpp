#pragma once

#include <string>
#include <map>

#include "common.hpp"

namespace silver::graphic
{
	class Shader
	{
	public:
		static std::unique_ptr<Shader> create(const std::string& file);

		virtual void bind() const = 0;
		virtual void unbind() const = 0;

	protected:
		//using Position = BufferDataName;
		virtual void compile() = 0;
	};
}