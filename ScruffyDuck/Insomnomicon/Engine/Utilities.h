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

		static Vec2<T> operator+(Vec2<T> lhs, const Vec2<T>& rhs)
		{
			lhs += rhs;
			return lhs;
		}


		//Vec2<T>& operator/(int value)
		//{
		//	Vec2<T> temp(const this);
		//	temp.x /= value;
		//	temp.y /= value;
		//
		//	return *temp;
		//}

		//Vec2<T>& operator/(float value)
		//{
		//	Vec2<T> temp(this);
		//	temp.x /= value;
		//	temp.y /= value;
		//
		//	return *temp;
		//}
		//
		//Vec2<T>& operator*(int value)
		//{
		//	Vec2<T> temp(this);
		//	temp.x *= value;
		//	temp.y *= value;
		//
		//	return *temp;
		//}
		//
		//Vec2<T>& operator*(float value)
		//{
		//	Vec2<T> temp(this);
		//	temp.x *= value;
		//	temp.y *= value;
		//
		//	return *temp;
		//}
	};
}