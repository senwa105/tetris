#ifndef VEC2_H
#define VEC2_H

template <typename T>
class Vec2 {
private:
    T x_;
    T y_;

public:
    Vec2() = default;

    constexpr Vec2(T x, T y)
        : x_(x),
          y_(y)
    {}

    constexpr T GetX() const { return x_; }
    constexpr T GetY() const { return y_; }
    constexpr void SetX(T x) { x_ = x; }
    constexpr void SetY(T y) { y_ = y; }

    constexpr Vec2 operator+(const Vec2& rhs) const {
        return Vec2{x_ + rhs.x_, y_ + rhs.y_};
    }

    constexpr Vec2 operator+(const int rhs) const {
        return Vec2{x_ + rhs, y_ + rhs};
    }

    constexpr Vec2& operator+=(const Vec2& rhs) {
        return *this = *this + rhs;
    }

    constexpr Vec2 operator-(const Vec2& rhs) const {
        return Vec2{x_ - rhs.x_, y_ - rhs.y_};
    }

    constexpr Vec2 operator-(const int rhs) const {
        return Vec2{x_ - rhs, y_ - rhs};
    }

    constexpr Vec2& operator-=(const Vec2& rhs) {
        return *this = *this - rhs;
    }

    constexpr Vec2 operator*(const Vec2& rhs) const {
        return Vec2{x_ * rhs.x_, y_ * rhs.y_};
    }

    constexpr Vec2 operator*(const int rhs) const {
        return Vec2{x_ * rhs, y_ * rhs};
    }

    constexpr Vec2& operator*=(const Vec2& rhs) {
        return *this = *this * rhs;
    }

    constexpr bool operator==(const Vec2& rhs) const {
        return x_ == rhs.x_ && y_ == rhs.y_;
    }

    constexpr bool operator!=(const Vec2& rhs) const {
        return !(*this == rhs);
    }
};

#endif