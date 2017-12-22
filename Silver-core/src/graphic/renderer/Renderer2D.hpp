#pragma once

#include "graphic\renderer\Renderer.hpp"
#include "graphic\shader\Shader.hpp"
#include "graphic\entity\Renderable2D.hpp"
#include "graphic\buffer\VertexBuffer.hpp"
#include "graphic\buffer\IndexBuffer.hpp"
#include "graphic\buffer\VertexArray.hpp"

namespace silver::graphic
{
	class Renderer2D
	{
	public:
		Renderer2D(const vec2ui viewportSize, std::unique_ptr<Shader>&& shader);
		~Renderer2D();

		void begin() const noexcept;
		void submit(const Renderable2D& object) noexcept;
		void submit(const Mesh* object) noexcept;
		void render() const noexcept;
		void end() const noexcept {};

	private:
		std::unique_ptr<Shader> shader_;
		std::unique_ptr<IndexBuffer> indexBuffer_;
		std::unique_ptr<VertexArray> vertexArray_;
		std::unique_ptr<BufferLayout> layout_;

		vec2ui viewportSize_ {};

		void init_() noexcept;
	};
}