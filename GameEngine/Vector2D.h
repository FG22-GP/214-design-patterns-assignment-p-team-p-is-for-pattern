#ifndef VECTOR2D_H
#define VECTOR2D_H
#include <math.h>


class Vector2D
{
public:
	
	Vector2D() :m_x(0), m_y(0) {}
	
	Vector2D(float x, float y) : m_x(x), m_y(y) {}

	float GetX() { return m_x; }
	float GetY() { return m_y; }

	void SetX(float x) { m_x = x; }
	void SetY(float y) { m_y = y; }

	float Lenght() { return sqrt(m_x * m_x + m_y * m_y); }

	Vector2D operator+ (const Vector2D& v2) const
	{
		return Vector2D(m_x + v2.m_x, m_y + v2.m_y);
	}
	friend Vector2D operator+= (Vector2D& v1, Vector2D& v2)
	{
		v1.m_x += v2.m_x;
		v1.m_y += v2.m_y;
		return v1;
	}

	Vector2D operator*(float scalar)
	{
		return Vector2D(m_x * scalar, m_y * scalar);
	}
	
	Vector2D& operator*=(float scalar)
	{
		m_x *= scalar;
		m_y *= scalar;
		return *this;
	}

	Vector2D operator-(const Vector2D& v2) const
	{
		return Vector2D(m_x - v2.m_x, m_y - v2.m_y);
	}
	friend Vector2D& operator-=(Vector2D& v1, const Vector2D& v2)
	{
		v1.m_x -= v2.m_x;
		v1.m_y -= v2.m_y;
		return v1;
	}

	Vector2D operator/(float scalar)
	{
		return Vector2D(m_x / scalar, m_y / scalar);
	}
	Vector2D& operator/=(float scalar)
	{
		m_x /= scalar;
		m_y /= scalar;
		return *this;
	}

	void Normalize()
	{
		float length = Lenght();
		if (length > 0)
		{
			(*this *= 1 / length);
		}
	}

private:

	float m_x;
	float m_y;
};



#endif // !VECTOR2D_H
