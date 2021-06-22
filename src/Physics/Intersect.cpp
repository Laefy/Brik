#include "Intersect.h"

std::optional<IntersectResult> Intersect(const Segment& s1, const Segment& s2)
{
    const auto v1 = s1.second - s1.first;
    const auto v2 = s2.second - s2.first;

    const auto d = s2.first - s1.first;

    const auto v1_x_v2 = Cross(v1, v2);
    const auto d_x_v1  = Cross(d, v1);

    if (const auto are_parallel = IsEpsilon(v1_x_v2))
    {
        return std::nullopt;
    }

    const auto t = Cross(d, v2) / v1_x_v2;
    const auto u = Cross(d, v1) / v1_x_v2;

    if (const auto intersect = IsInRange(t, 0, 1) && IsInRange(u, 0, 1); !intersect)
    {
        return std::nullopt;
    }

    return IntersectResult { s1.first + t * v1, t };
}
