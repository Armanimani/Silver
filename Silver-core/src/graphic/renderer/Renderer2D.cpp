#include "graphic\renderer\Renderer2D.hpp"
#include "graphic\renderer\Renderer.hpp"

#include <GL\glew.h>

namespace silver::graphic
{
	Renderer2D::Renderer2D(const vec2ui viewportSize, std::unique_ptr<Shader>&& shader) : viewportSize_(std::move(viewportSize)), shader_(std::move(shader))
	{
		init_();
	}

	Renderer2D::~Renderer2D() {}

	void Renderer2D::begin() const noexcept
	{

	}

	void Renderer2D::submit(const Renderable2D& object) noexcept
	{

	}

	void Renderer2D::submit(const Mesh* object) noexcept
	{
		object->vertexArray->bind();
		object->indexBuffer->bind();
		glDrawElements(GL_TRIANGLES, object->indexBuffer->count(), object->indexBuffer->dataType(), 0);
		object->indexBuffer->unbind();
		object->vertexArray->unbind();
	}

	void Renderer2D::render() const noexcept
	{
		
	}

	void Renderer2D::init_() noexcept
	{
		//layout_->push(BufferData::POSITION, BufferDataType::VEC3F);
		//layout_->push(BufferData::COLOR, BufferDataType::VEC3F);
	}
}