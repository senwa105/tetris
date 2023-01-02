#ifndef VEC2_H
#define VEC2_H

template <typename T>
class Vec2 {
private:
    T x_{};
    T y_{};

public:
    constexpr Vec2() = default;

    constexpr Vec2(T x, T y)
        : x_(x),
          y_(y)
    {}

    T GetX() const { return x_; }
    T GetY() const { return y_; }
    void SetX(T x) { x_ = x; }
    void SetY(T y) { y_ = y; }

    Vec2 operator+(const Vec2& rhs) const {
        return Vec2{x_ + rhs.x_, y_ + rhs.y_};
    }

    Vec2 operator+(const int rhs) const {
        return Vec2{x_ + rhs, y_ + rhs};
    }

    Vec2& operator+=(const Vec2& rhs) {
        return *this = *this + rhs;
    }

    Vec2 operator-(const Vec2& rhs) const {
        return Vec2{x_ - rhs.x_, y_ - rhs.y_};
    }

    Vec2 operator-(const int rhs) const {
        return Vec2{x_ - rhs, y_ - rhs};
    }

    Vec2& operator-=(const Vec2& rhs) {
        return *this = *this - rhs;
    }

    Vec2 operator*(const Vec2& rhs) const {
        return Vec2{x_ * rhs.x_, y_ * rhs.y_};
    }

    Vec2 operator*(const int rhs) const {
        return Vec2{x_ * rhs, y_ * rhs};
    }

    Vec2& operator*=(const Vec2& rhs) {
        return *this = *this * rhs;
    }

    bool operator==(const Vec2& rhs) const {
        return x_ == rhs.x_ && y_ == rhs.y_;
    }

    bool operator!=(const Vec2& rhs) const {
        return !(*this == rhs);
    }
};

#endif