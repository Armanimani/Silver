#pragma once

#include "graphic\scene\layer\Layer.hpp"
#include "graphic\shader\Shader.hpp"
#include "graphic\buffer\BufferLayout.hpp"
#include "util\logger\Logger.hpp"
#include "graphic\renderer\Renderer2D.hpp"
#include "graphic\mesh\MeshCreator.hpp"

using namespace silver::graphic;
using namespace silver::core;

class TestLayer2D : public Layer
{
public:
	TestLayer2D()
	{

	}

	void on_init() noexcept override
	{

		shader_ = Shader::create("res/shader/Basic.shader");
		shader_->bind();

		mesh = MeshCreator::rectangle(0.8f, 0.4f);
		mesh2 = MeshCreator::hello_triangle();

		vec2ui vec = { 800, 600 };
		renderer_ = std::make_unique<Renderer2D>(vec, std::move(shader_));


		//Vertex3D v1;
		//v1.position = { -1.0f, -1.0f, 0.0f };
		//Vertex3D v2;
		//v2.position = { 1.0f, -1.0f, 0.0f };
		//Vertex3D v3;
		//v3.position = { 0.0f, 1.0f, 0.0f };


		//auto verts = std::vector<Vertex3D> { v1, v2, v3 };
		//auto index = std::vector<uint> { 0, 1, 2 };

		//auto mesh = Mesh(std::move(verts), std::move(index));

		//renderer_->submit(&mesh);

		

		//auto layout = BufferLayout::create();
		//layout->push(BufferDataName::POSITION, BufferDataTypeName::VEC3F);
		//layout->push(BufferDataName::COLOR, BufferDataTypeName::VEC3F);
		//auto res = layout->apply(&mesh);

		//auto f = *reinterpret_cast<float*>(&res[24]);
		//Logger::instance().log(f);

		//std::vector<uint> index
		//{
		//	0, 1, 2
		//};

		//auto layout = silver::graphic::BufferLayout::create();
		//layout->push(silver::graphic::BufferDataName::POSITION, silver::graphic::BufferDataType::VEC3F, false);

		//mesh_ = std::make_unique<silver::graphic::Mesh>(static_cast<const void*>(&verts[0]), sizeof(verts), std::move(layout), static_cast<const void*>(&index[0]), sizeof(index));
	}

	void on_render() noexcept override
	{
		renderer_->submit(mesh.get());
		renderer_->submit(mesh2.get());
	}

	void on_window_resize(const vec2ui size) noexcept override
	{
		Renderer::instance()->set_viewport({ 0, 0 }, size);
	}

protected:
	std::unique_ptr<Shader> shader_;
	std::unique_ptr<Renderer2D> renderer_;
	std::unique_ptr<Mesh> mesh;
	std::unique_ptr<Mesh> mesh2;

};