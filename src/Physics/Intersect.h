#pragma once

#include "Geometry.h"

#include <SFML/System/Vector2.hpp>
#include <optional>

struct IntersectResult
{
    sf::Vector2f position;
    float rate = 1.f;
};

std::optional<IntersectResult> Intersect(const Segment& s1, const Segment& s2);
