#include "graphic\shader\Shader.hpp"

#include "graphic\context\Context.hpp"
#include "graphic\system\OpenGL\GLShader.hpp"

namespace silver::graphic
{
	std::unique_ptr<Shader> Shader::create(const std::string& file)
	{
		if (Context::instance()->API() == RenderingContext_API::OpenGL)
		{
			std::unique_ptr<Shader> p = std::make_unique<GLShader>(file);
			return p;
		}
		else
		{
			throw SILVER_EXCEPTION_CRITICAL("Unsupported Shader platform");
		}
	}
}