#pragma once

#include <SFML/System/Vector2.hpp>
#include <cmath>
#include <cstdlib>
#include <limits>
#include <utility>

struct Sphere
{
    sf::Vector2f center;
    float radius = 1.f;
};

using Segment = std::pair<sf::Vector2f, sf::Vector2f>;

struct Rectangle
{
    sf::Vector2f top_left;
    sf::Vector2f bottom_right;
};

inline float Length(const sf::Vector2f& v)
{
    return std::sqrt(v.x * v.x + v.y * v.y);
}

inline float Dot(const sf::Vector2f& v1, const sf::Vector2f& v2)
{
    return v1.x * v2.x + v1.y * v2.y;
}

inline float Cross(const sf::Vector2f& v1, const sf::Vector2f& v2)
{
    return v1.x * v2.y - v1.y * v2.x;
}

inline sf::Vector2f Scale(const sf::Vector2f& v, float length)
{
    return v * length / Length(v);
}

inline sf::Vector2f Project(const sf::Vector2f& p, const Segment& s)
{
    const auto sp = p - s.first;
    const auto d  = Scale(s.second - s.first, 1.f);
    return s.first + Dot(sp, d) * d;
}

inline sf::Vector2f Normal(const Segment& s)
{
    const auto d = s.second - s.first;
    return Scale(sf::Vector2f { -d.y, d.x }, 1);
}

inline bool IsEpsilon(float value)
{
    return std::abs(value) < std::numeric_limits<float>::epsilon();
}

inline bool IsInRange(float value, float min, float max)
{
    return min <= value && value <= max;
}
