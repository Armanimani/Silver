//#pragma once
//
//#include <memory>
//
//#include "common.hpp"
//#include "graphic\buffer\VertexArray.hpp"
//#include "graphic\buffer\VertexBuffer.hpp"
//#include "graphic\batch\BatchConfig.hpp"
//
//namespace silver::core::graphic
//{
//	class Batch
//	{
//	public:
//		Batch(const uint maxSize = 512000);
//		
//		void submit(const void* data, const uint dataSize);
//
//		uint capacity() const noexcept;
//		uint max_size() const noexcept;
//		BatchConfig config() const noexcept; 
//		uint priority() const noexcept;
//		void set_config(const BatchConfig config) noexcept;
//
//	private:
//		BatchConfig config_;
//		uint maxSize_;
//		uint size_;
//
//		std::unique_ptr<VertexArray> vertexArray_;
//		std::unique_ptr<VertexBuffer> vertexBuffer_;
//	};
//}