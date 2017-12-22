#pragma once

#include "graphic\shader\Shader.hpp"

namespace silver::graphic
{
	class GLShader : public Shader
	{
	public:
		struct Source
		{
			std::string vertex;
			std::string fragment;
		};

		GLShader(const std::string& file);
		~GLShader();

		void bind() const override;
		void unbind() const override;

	private:
		const std::string VERTEX_SHADER { "vertex" };
		const std::string FRAGMENT_SHADER { "fragment" };

		uint handle_ {};
		Source source_;
		
		void parse_shaders_(const std::string& file);

		void compile() override;
		void compile_shader(const uint32 handle, const std::string& code);

		void check_shader_status(const uint32 shaderID);
		void check_program_status(const uint32 programID);

		int32 get_uniform_location_(const std::string& name) const;

		void set_uniform_(const std::string& name, const float value) const;
		void set_uniform_(const std::string& name, const vec2f value) const;
		void set_uniform_(const std::string& name, const vec3f value) const;
		void set_uniform_(const std::string& name, const vec4f value) const;
		void set_uniform_(const std::string& name, const int32 value) const;
		void set_uniform_(const std::string& name, const vec2i value) const;
		void set_uniform_(const std::string& name, const vec3i value) const;
		void set_uniform_(const std::string& name, const vec4i value) const;
		void set_uniform_(const std::string& name, const mat3 value) const;
		void set_uniform_(const std::string& name, const mat4 value) const;
		void set_uniform_(const std::string& name, const uint count, const float* value) const;
		void set_uniform_(const std::string& name, const uint count, const int32* value) const;
	};
}