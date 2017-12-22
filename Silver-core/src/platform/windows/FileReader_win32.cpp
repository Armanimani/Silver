#include "platform\windows\FileReader_win32.hpp"

#include <fstream>
#include <sstream>

#include "common.hpp"

namespace silver::core
{
	std::string FileReader_win32::convert_to_string(const std::string path)
	{
		std::ifstream file(path);
		if (!file.good())
		{
			throw SILVER_EXCEPTION_CRITICAL("unable to open the file" + path);
		}
		return std::string(std::istreambuf_iterator<char>(file), std::istreambuf_iterator<char>());
	}

	silver::graphic::GLShader::Source FileReader_win32::parse_GLShader(const std::string& filePath)
	{
		enum class Type
		{
			NO_TYPE = 0,
			VERTEX = 1,
			FRAGMENT = 2
		};
		silver::graphic::GLShader::Source ret;

		std::fstream file(filePath);
		std::string line;
		std::stringstream sstream[2];
		Type type;
		bool cond { false };

		while (getline(file, line))
		{
			if (line.find("#shader") != std::string::npos)
			{
				if (line.find("vertex") != std::string::npos)
				{
					type = Type::VERTEX;
				}
				else if (line.find("fragment") != std::string::npos)
				{
					type = Type::FRAGMENT;
				}
			}
			else
			{
				if (type != Type::NO_TYPE)
					sstream[static_cast<uint>(type) - 1] << line << '\n';
			}
		}

		ret.vertex = sstream[static_cast<uint>(Type::VERTEX) - 1].str();
		ret.fragment = sstream[static_cast<uint>(Type::FRAGMENT) - 1].str();

		return ret;
	}
}
