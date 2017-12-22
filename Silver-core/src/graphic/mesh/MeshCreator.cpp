#include "graphic/mesh/MeshCreator.hpp"

#include "graphic/buffer/VertexArray.hpp"
#include "graphic/buffer/IndexBuffer.hpp"

namespace silver::graphic
{
	std::unique_ptr<silver::graphic::Mesh> MeshCreator::hello_triangle() noexcept
	{
		std::vector<float> verts 
		{
			-0.5f, -0.5f, 0.0f,
			+0.0f, +0.5f, 0.0f,
			+0.5f, -0.5f, 0.0f 
		};

		std::vector<uint> indices
		{
			2, 1, 0
		};

		auto vao = VertexArray::create();
		auto vbo = VertexBuffer::create();
		auto ibo = IndexBuffer::create();

		auto layout = BufferLayout::create();
		layout->push(BufferData::POSITION, BufferDataType::VEC3F);
		vbo->set_data(&verts[0], static_cast<uint>(verts.size() * sizeof(float)));
		ibo->set_data(&indices[0], static_cast<uint>(indices.size()));
		vao->set_buffer(std::move(vbo), std::move(layout));

		return std::make_unique<Mesh> (std::move(vao), std::move(ibo));
	}

	std::unique_ptr<silver::graphic::Mesh> MeshCreator::rectangle(const float width, const float height) noexcept
	{
		std::vector<float> verts
		{
			-0.5f * width, -0.5f * height, 0.0f,
			-0.5f * width, +0.5f * height, 0.0f,
			+0.5f * width, +0.5f * height, 0.0f,
			+0.5f * width, -0.5f * height, 0.0f
		};

		std::vector<uint> indices
		{
			2, 1, 0, 0, 3, 2
		};

		auto vao = VertexArray::create();
		auto vbo = VertexBuffer::create();
		auto ibo = IndexBuffer::create();

		auto layout = BufferLayout::create();
		layout->push(BufferData::POSITION, BufferDataType::VEC3F);
		vbo->set_data(&verts[0], static_cast<uint>(verts.size() * sizeof(float)));
		ibo->set_data(&indices[0], static_cast<uint>(indices.size()));
		vao->set_buffer(std::move(vbo), std::move(layout));

		return std::make_unique<Mesh>(std::move(vao), std::move(ibo));
	}
}