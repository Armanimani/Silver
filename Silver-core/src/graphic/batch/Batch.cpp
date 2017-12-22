//#include "graphic\batch\Batch.hpp"
//
//#include "util\logger\Logger.hpp"
//
//namespace silver::core::graphic
//{
//	const uint MAXIMUM_SIZE = 4194304; // 4MB
//	Batch::Batch(const uint maxSize)
//	{
//		if (maxSize_ >= MAXIMUM_SIZE)
//			Logger::instance().log_warning("Large batch size = " + std::to_string(maxSize / 1024.0f / 1024.0f) + "MB");
//	}
//
//	void submit(const void* data, const uint dataSize)
//	{
//
//	}
//
//	uint Batch::capacity() const noexcept
//	{
//		return size_ - maxSize_;
//	}
//
//	uint Batch::max_size() const noexcept
//	{
//		return maxSize_;
//	}
//
//	BatchConfig Batch::config() const noexcept
//	{
//		return config_;
//	}
//
//	uint Batch::priority() const noexcept
//	{
//		return config_.priority;
//	}
//
//	void Batch::set_config(const BatchConfig config) noexcept
//	{
//		config_ = config;
//	}
//}