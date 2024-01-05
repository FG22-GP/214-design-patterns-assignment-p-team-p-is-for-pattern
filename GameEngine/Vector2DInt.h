#pragma once
#include <math.h>

class Vector2DInt {
public:
    Vector2DInt() : m_x(0), m_y(0) {
    }

    Vector2DInt(int x, int y) : m_x(x), m_y(y) {
    }

    int GetX() { return m_x; }
    int GetY() { return m_y; }

    Vector2DInt SetX(int x) {
        m_x = x;
        return *this;
    }

    Vector2DInt SetY(int y) {
        m_y = y;
        return *this;
    }

    int Lenght() { return sqrt(m_x * m_x + m_y * m_y); }

    Vector2DInt operator+(const Vector2DInt& v2) const {
        return Vector2DInt(m_x + v2.m_x, m_y + v2.m_y);
    }

    friend Vector2DInt operator+=(Vector2DInt& v1, Vector2DInt& v2) {
        v1.m_x += v2.m_x;
        v1.m_y += v2.m_y;
        return v1;
    }

    Vector2DInt operator*(int scalar) {
        return Vector2DInt(m_x * scalar, m_y * scalar);
    }

    Vector2DInt& operator*=(int scalar) {
        m_x *= scalar;
        m_y *= scalar;
        return *this;
    }

    Vector2DInt operator-(const Vector2DInt& v2) const {
        return Vector2DInt(m_x - v2.m_x, m_y - v2.m_y);
    }

    friend Vector2DInt& operator-=(Vector2DInt& v1, const Vector2DInt& v2) {
        v1.m_x -= v2.m_x;
        v1.m_y -= v2.m_y;
        return v1;
    }

    Vector2DInt operator/(int scalar) {
        return Vector2DInt(m_x / scalar, m_y / scalar);
    }

    Vector2DInt& operator/=(int scalar) {
        m_x /= scalar;
        m_y /= scalar;
        return *this;
    }

    void Normalize() {
        float length = Lenght();
        if (length > 0) {
            (*this *= 1 / length);
        }
    }

    //TODO: DotPRoduct;

    static float Distance(Vector2DInt& v1, Vector2DInt& v2) {
        return static_cast<int>(sqrt(pow((v1.GetX() - v2.GetX()), 2) + pow((v1.GetY() - v2.GetY()), 2)));
    }

private:
    int m_x;
    int m_y;
};
