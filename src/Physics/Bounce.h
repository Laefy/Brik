#pragma once

#include "Geometry.h"

#include <SFML/System/Vector2.hpp>
#include <limits>

struct BounceResult
{
    sf::Vector2f destination;
    sf::Vector2f direction;
    float rate = std::numeric_limits<float>::max();
};

bool Bounce(BounceResult& result, const Sphere& sphere, const sf::Vector2f& speed, const Segment& segment);
bool Bounce(BounceResult& result, const Sphere& sphere, const sf::Vector2f& speed, const Rectangle& rectangle);
