#include "Bounce.h"

#include "Intersect.h"

bool Bounce(BounceResult& result, const Sphere& sphere, const sf::Vector2f& speed, const Segment& segment)
{
    const auto speed_length = Length(speed);
    if (IsEpsilon(speed_length))
    {
        return false;
    }

    const auto dest       = sphere.center + speed;
    const auto adjustment = speed * sphere.radius / speed_length;

    const auto adjusted_dest = dest + adjustment;
    const Segment sphere_segment { sphere.center + adjustment, adjusted_dest };

    if (const auto intersect_result = Intersect(sphere_segment, segment);
        intersect_result && intersect_result->rate < result.rate)
    {
        const auto projection = Project(adjusted_dest, segment);
        const auto normal     = Normal(segment);

        result.destination = 2.f * projection - adjusted_dest;
        result.direction   = -2 * Dot(normal, speed) * normal + speed;
        result.rate        = intersect_result->rate;

        return true;
    }

    return false;
}

bool Bounce(BounceResult& result, const Sphere& sphere, const sf::Vector2f& speed, const Rectangle& rectangle)
{
    const sf::Vector2f top_right { rectangle.bottom_right.x, rectangle.top_left.y };
    const sf::Vector2f bottom_left { rectangle.top_left.x, rectangle.bottom_right.y };

    auto bounced = false;
    bounced |= Bounce(result, sphere, speed, Segment { rectangle.top_left, top_right });
    bounced |= Bounce(result, sphere, speed, Segment { rectangle.top_left, bottom_left });
    bounced |= Bounce(result, sphere, speed, Segment { top_right, rectangle.bottom_right });
    bounced |= Bounce(result, sphere, speed, Segment { bottom_left, rectangle.bottom_right });

    return bounced;
}