#pragma once

namespace NSimp
{
	template <typename T>
	struct Vec3
	{
		T x, y, z;

		Vec3()
		{
			x = NULL;
			y = NULL;
			z = NULL;
		}

		Vec3(T xStarting, T yStarting, T zStarting)
		{
			x = xStarting;
			y = yStarting;
			z = zStarting;
		}
	};

	template <typename T>
	struct Vec2
	{
		T x, y;

		Vec2()
		{
			x = NULL;
			y = NULL;
		}

		Vec2(T xStarting, T yStarting)
		{
			x = xStarting;
			y = yStarting;
		}

		Vec2(const Vec2<T>& incoming)
		{
			x = incoming.x;
			y = incoming.y;
		}

		Vec2<T>& operator+=(const Vec2<T>& value)
		{
			x += value.x;
			y += value.y;

			return *this;
		}

		Vec2<T>& operator/=(const float& value)
		{
			x /= value;
			y /= value;

			return *this;
		}

		Vec2<T>& operator*=(const float& value)
		{
			x *= value;
			y *= value;

			return *this;
		}
	};

	template <typename T>
	inline Vec2<T> operator+(Vec2<T> lhs, const Vec2<T>& rhs)
	{
		lhs += rhs;
		return lhs;
	}
	
	template <typename T>
	inline Vec2<T> operator*(Vec2<T> lhs, const float& rhs)
	{
		lhs *= rhs;
		return lhs;
	}
	
	template <typename T>
	inline Vec2<T> operator/(Vec2<T> lhs, const float& rhs)
	{
		lhs /= rhs;
		return lhs;
	}
}