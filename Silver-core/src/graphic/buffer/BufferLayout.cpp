#include "graphic\buffer\BufferLayout.hpp"

#include <algorithm>

#include "graphic\context\Context.hpp"
#include "graphic\system\OpenGL\GLBufferLayout.hpp"
#include "common.hpp"

namespace silver::graphic
{
	std::unique_ptr<BufferLayout> BufferLayout::create()
	{
		if (Context::API() == RenderingContext_API::OpenGL)
		{
			std::unique_ptr<BufferLayout> p = std::make_unique<GLBufferLayout>();
			return p;
		}
		else
		{
			throw SILVER_EXCEPTION_CRITICAL("Unsupported buffer layout specification");
		}
	}

	BufferData BufferLayout::name(const uint index) const
	{
		if (index >= structures_.size())
			throw SILVER_EXCEPTION_CRITICAL("Unable to access the bufferlayout of index " + std::to_string(index) + " maxSsize = " + std::to_string(structures_.size()));
		return structures_[index].name;
	}

	void BufferLayout::push(const BufferData name, const BufferDataType dataType, const bool normalized)
	{
		switch (dataType)
		{
			default:
			{
				throw SILVER_EXCEPTION_CRITICAL("Unsupported GLbufferLayout data type");
			}
			case BufferDataType::BYTE:
			{
				push_byte_(name, 1, normalized, dataType);
				break;
			}
			case BufferDataType::VEC2B:
			{
				push_byte_(name, 2, normalized, dataType);
				break;
			}
			case BufferDataType::VEC3B:
			{
				push_byte_(name, 3, normalized, dataType);
				break;
			}
			case BufferDataType::VEC4B:
			{
				push_byte_(name, 4, normalized, dataType);
				break;
			}
			case BufferDataType::UNSIGNED_INT:
			{
				push_uint_(name, 1, normalized, dataType);
				break;
			}
			case BufferDataType::VEC2UI:
			{
				push_uint_(name, 2, normalized, dataType);
				break;
			}
			case BufferDataType::VEC3UI:
			{
				push_uint_(name, 3, normalized, dataType);
				break;
			}
			case BufferDataType::VEC4UI:
			{
				push_uint_(name, 4, normalized, dataType);
				break;
			}
			case BufferDataType::FLOAT:
			{
				push_float_(name, 1, normalized, dataType);
				break;
			}
			case BufferDataType::VEC2F:
			{
				push_float_(name, 2, normalized, dataType);
				break;
			}
			case BufferDataType::VEC3F:
			{
				push_float_(name, 3, normalized, dataType);
				break;
			}
			case BufferDataType::VEC4F:
			{
				push_float_(name, 4, normalized, dataType);
				break;
			}
		}
	}

	//std::vector<Byte> BufferLayout::apply(const RawMesh* mesh) const
	//{
	//	std::vector<Byte> bytes;
	//	auto verts = mesh->verts;
	//	for (auto v = verts.cbegin(); v != verts.cend(); ++v)
	//	{
	//		auto vert = *v;
	//		std::vector<Byte> temp;
	//		for (auto i = structures_.cbegin() ; i != structures_.cend(); ++i)
	//		{
	//			void* ptr;
	//			switch (i->name)
	//			{
	//				case (BufferData::POSITION):
	//				{
	//					ptr = &vert.position;
	//					break;
	//				}
	//				case (BufferData::COLOR):
	//				{
	//					ptr = &vert.color;
	//					break;
	//				}
	//				case (BufferData::NORMAL):
	//				{
	//					ptr = &vert.normal;
	//					break;
	//				}
	//			}

	//			switch (i->dataType)
	//			{
	//				case (BufferDataType::FLOAT):
	//				{
	//					auto beg = reinterpret_cast<Byte*>(ptr);
	//					temp.insert(temp.end(), beg, beg + 1 * sizeof(float));
	//					break;
	//				}
	//				case (BufferDataType::VEC2F):
	//				{
	//					auto beg = reinterpret_cast<Byte*>(ptr);
	//					temp.insert(temp.end(), beg, beg + 2 * sizeof(float));
	//					break;
	//				}
	//				case (BufferDataType::VEC3F):
	//				{
	//					auto beg = reinterpret_cast<Byte*>(ptr);
	//					temp.insert(temp.end(), beg, beg + 3 * sizeof(float));
	//					break;
	//				}
	//				case (BufferDataType::VEC4F):
	//				{
	//					auto beg = reinterpret_cast<Byte*>(ptr);
	//					temp.insert(temp.end(), beg, beg + 4 * sizeof(float));
	//					break;
	//				}
	//				case (BufferDataType::UNSIGNED_INT):
	//				{
	//					auto beg = reinterpret_cast<Byte*>(ptr);
	//					temp.insert(temp.end(), beg, beg + 1 * sizeof(uint));
	//					break;
	//				}
	//				case (BufferDataType::VEC2UI):
	//				{
	//					auto beg = reinterpret_cast<Byte*>(ptr);
	//					temp.insert(temp.end(), beg, beg + 2 * sizeof(uint));
	//					break;
	//				}
	//				case (BufferDataType::VEC3UI):
	//				{
	//					auto beg = reinterpret_cast<Byte*>(ptr);
	//					temp.insert(temp.end(), beg, beg + 3 * sizeof(uint));
	//					break;
	//				}
	//				case (BufferDataType::VEC4UI):
	//				{
	//					auto beg = reinterpret_cast<Byte*>(ptr);
	//					temp.insert(temp.end(), beg, beg + 4 * sizeof(uint));
	//					break;
	//				}
	//				case (BufferDataType::BYTE):
	//				{
	//					auto beg = reinterpret_cast<Byte*>(ptr);
	//					temp.insert(temp.end(), beg, beg + 1 * sizeof(Byte));
	//					break;
	//				}
	//				case (BufferDataType::VEC2B):
	//				{
	//					auto beg = reinterpret_cast<Byte*>(ptr);
	//					temp.insert(temp.end(), beg, beg + 2 * sizeof(Byte));
	//					break;
	//				}
	//				case (BufferDataType::VEC3B):
	//				{
	//					auto beg = reinterpret_cast<Byte*>(ptr);
	//					temp.insert(temp.end(), beg, beg + 3 * sizeof(Byte));
	//					break;
	//				}
	//				case (BufferDataType::VEC4B):
	//				{
	//					auto beg = reinterpret_cast<Byte*>(ptr);
	//					temp.insert(temp.end(), beg, beg + 4 * sizeof(Byte));
	//					break;
	//				}
	//			}
	//		}
	//		bytes.insert(bytes.end(), temp.begin(), temp.end());
	//	}
	//	return bytes;
	//}
}