#pragma once

#include <memory>

#include "math\Vector2.hpp"

namespace silver::core
{
	template <typename T>
	struct Vector3
	{
	public:
		Vector3() = default;
		explicit Vector3(const T value) : x(value), y(value), z(value) {}
		explicit Vector3(const Vector2<T> vec) : x(vec.x), y(vec.y) {}
		Vector3(const T m_x, const T m_y, const T m_z) : x(std::move(m_x)), y(std::move(m_y)), z(std::move(m_z)) {}

		Vector3(const Vector3& rhs) noexcept = default;
		Vector3(Vector3&& rhs) noexcept = default;

		Vector3& operator=(const Vector3& rhs) noexcept = default;
		Vector3& operator=(Vector3&& rhs) noexcept = default;

		Vector3 operator+() const noexcept;
		Vector3 operator-() const noexcept;
		Vector3 operator+(const Vector3& rhs) const noexcept;
		Vector3 operator-(const Vector3& rhs) const noexcept;
		Vector3 operator*(const Vector3& rhs) const noexcept;
		Vector3& operator+=(const Vector3& rhs) noexcept;
		Vector3& operator-=(const Vector3& rhs) noexcept;
		Vector3& operator*=(const Vector3& rhs) noexcept;
		bool operator==(const Vector3& rhs) const noexcept;
		bool operator!=(const Vector3& rhs) const noexcept;

		T x {};
		T y {};
		T z {};
	};

	template <typename T>
	Vector3<T> Vector3<T>::operator+() const noexcept
	{
		return { x, y, z };
	}

	template <typename T>
	Vector3<T> Vector3<T>::operator-() const noexcept
	{
		return { -x, -y, -z };
	}

	template <typename T>
	Vector3<T> Vector3<T>::operator+(const Vector3<T>& rhs) const noexcept
	{
		return { x + rhs.x, y + rhs.y, z + rhs.z };
	}

	template <typename T>
	Vector3<T> Vector3<T>::operator-(const Vector3<T>& rhs) const noexcept
	{
		return { x - rhs.x, y - rhs.y, z - rhs.z };
	}

	template <typename T>
	Vector3<T> Vector3<T>::operator*(const Vector3<T>& rhs) const noexcept
	{
		return { x * rhs.x, y * rhs.y, z * rhs.z };
	}

	template <typename T>
	Vector3<T>& Vector3<T>::operator+=(const Vector3<T>& rhs) noexcept
	{
		x += rhs.x;
		y += rhs.y;
		z += rhs.z;
		return *this;
	}

	template <typename T>
	Vector3<T>& Vector3<T>::operator-=(const Vector3<T>& rhs) noexcept
	{
		x -= rhs.x;
		y -= rhs.y;
		z -= rhs.z;
		return *this;
	}

	template <typename T>
	Vector3<T>& Vector3<T>::operator*=(const Vector3<T>& rhs) noexcept
	{
		x *= rhs.x;
		y *= rhs.y;
		z *= rhs.z;
		return *this;
	}

	template <typename T>
	bool Vector3<T>::operator==(const Vector3<T>& rhs) const noexcept
	{
		return !(*this != rhs);
	}

	template <typename T>
	bool Vector3<T>::operator!=(const Vector3<T>& rhs) const noexcept
	{
		return (x != rhs.x || y != rhs.y || z != rhs.z);
	}
}