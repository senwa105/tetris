#ifndef VECTOR2_H
#define VECTOR2_H

template <typename T>
class Vector2 {
private:
    T x_;
    T y_;

public:
    Vector2() = default;

    Vector2(T x, T y)
        : x_(x),
          y_(y)
    {}

    T GetX() const { return x_; }
    T GetY() const { return y_; }
    void SetX(T x) { x_ = x; }
    void SetY(T y) { y_ = y; }

    Vector2 operator+(const Vector2& rhs) const {
        return Vector2{x_ + rhs.x_, y_ + rhs.y_};
    }

    Vector2 operator+(const int rhs) {
        return Vector2{x_ + rhs, y_ + rhs};
    }

    Vector2& operator+=(const Vector2& rhs) {
        return *this = *this + rhs;
    }

    Vector2 operator-(const Vector2& rhs) const {
        return Vector2{x_ - rhs.x_, y_ - rhs.y_};
    }

    Vector2 operator-(const int rhs) {
        return Vector2{x_ - rhs, y_ - rhs};
    }

    Vector2& operator-=(const Vector2& rhs) {
        return *this = *this - rhs;
    }

    Vector2 operator*(const Vector2& rhs) const {
        return Vector2{x_ * rhs.x_, y_ * rhs.y_};
    }

    Vector2 operator*(const int rhs) {
        return Vector2{x_ * rhs, y_ * rhs};
    }

    Vector2& operator*=(const Vector2& rhs) {
        return *this = *this * rhs;
    }

    bool operator==(const Vector2& rhs) const {
        return x_ == rhs.x_ && y_ == rhs.y_;
    }

    bool operator!=(const Vector2& rhs) const {
        return !(*this == rhs);
    }
};

#endif