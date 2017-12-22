#pragma once

#include <memory>

#include "math\Vector2.hpp"
#include "math\Vector3.hpp"

namespace silver::core
{
	template <typename T>
	struct Vector4
	{
	public:
		Vector4() = default;
		explicit Vector4(const T value) : x(value), y(value), z(value), a(value) {}
		explicit Vector4(const Vector2<T> vec) : x(vec.x), y(vec.y) {}
		explicit Vector4(const Vector3<T> vec) : x(vec.x), y(vec.y), z(vec.z) {}
		Vector4(const T m_x, const T m_y, const T m_z, const T m_a) : x(std::move(m_x)), y(std::move(m_y)), z(std::move(m_z)), a(std::move(m_a)) {}

		Vector4(const Vector4& rhs) noexcept = default;
		Vector4(Vector4&& rhs) noexcept = default;

		Vector4& operator=(const Vector4& rhs) noexcept = default;
		Vector4& operator=(Vector4&& rhs) noexcept = default;

		Vector4 operator+() const noexcept;
		Vector4 operator-() const noexcept;
		Vector4 operator+(const Vector4& rhs) const noexcept;
		Vector4 operator-(const Vector4& rhs) const noexcept;
		Vector4 operator*(const Vector4& rhs) const noexcept;
		Vector4& operator+=(const Vector4& rhs) noexcept;
		Vector4& operator-=(const Vector4& rhs) noexcept;
		Vector4& operator*=(const Vector4& rhs) noexcept;
		bool operator==(const Vector4& rhs) const noexcept;
		bool operator!=(const Vector4& rhs) const noexcept;

		T x {};
		T y {};
		T z {};
		T a {};
	};

	template <typename T>
	Vector4<T> Vector4<T>::operator+() const noexcept
	{
		return { x, y, z, a };
	}

	template <typename T>
	Vector4<T> Vector4<T>::operator-() const noexcept
	{
		return { -x, -y, -z, -a };
	}

	template <typename T>
	Vector4<T> Vector4<T>::operator+(const Vector4<T>& rhs) const noexcept
	{
		return { x + rhs.x, y + rhs.y, z + rhs.z, a + rhs.a };
	}

	template <typename T>
	Vector4<T> Vector4<T>::operator-(const Vector4<T>& rhs) const noexcept
	{
		return { x - rhs.x, y - rhs.y, z - rhs.z, a - rhs.a };
	}

	template <typename T>
	Vector4<T> Vector4<T>::operator*(const Vector4<T>& rhs) const noexcept
	{
		return { x * rhs.x, y * rhs.y, z * rhs.z, a * rhs.a };
	}

	template <typename T>
	Vector4<T>& Vector4<T>::operator+=(const Vector4<T>& rhs) noexcept
	{
		x += rhs.x;
		y += rhs.y;
		z += rhs.z;
		a += rhs.a;
		return *this;
	}

	template <typename T>
	Vector4<T>& Vector4<T>::operator-=(const Vector4<T>& rhs) noexcept
	{
		x -= rhs.x;
		y -= rhs.y;
		z -= rhs.z;
		a -= rhs.a;
		return *this;
	}

	template <typename T>
	Vector4<T>& Vector4<T>::operator*=(const Vector4<T>& rhs) noexcept
	{
		x *= rhs.x;
		y *= rhs.y;
		z *= rhs.z;
		a *= rhs.a;
		return *this;
	}

	template <typename T>
	bool Vector4<T>::operator==(const Vector4<T>& rhs) const noexcept
	{
		return !(*this != rhs);
	}

	template <typename T>
	bool Vector4<T>::operator!=(const Vector4<T>& rhs) const noexcept
	{
		return (x != rhs.x || y != rhs.y || z != rhs.z || a != rhs.a);
	}
}