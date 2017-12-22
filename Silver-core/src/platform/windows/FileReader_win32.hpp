#pragma once

#include <string>
#include <vector>

#include "graphic/system/OpenGL/GLShader.hpp"

namespace silver::core
{
	class FileReader_win32
	{
	public:
		static std::string convert_to_string(const std::string path);
		static silver::graphic::GLShader::Source parse_GLShader(const std::string& file);
	};
}