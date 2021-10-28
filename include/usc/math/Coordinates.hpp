#pragma once

#include "usc/Visibility.hpp"
#include "usc/math/Angle.hpp"

// Primitives & helper functions
namespace usc::math {
struct USC_DLL_EXPORT Cartesian2 {
  double x, y;
};

const Cartesian2 OriginPoint2{0, 0};

struct USC_DLL_EXPORT Cartesian3 {
  double x, y, z;
};

const Cartesian3 OriginPoint3{0, 0, 0};

struct USC_DLL_EXPORT Polar {
  double radius;
  Angle theta;
};

USC_DLL_EXPORT double DistanceBetweenCartesian2(Cartesian2 a, Cartesian2 b);
USC_DLL_EXPORT Angle AngleBetweenCartesian2(Cartesian2 a, Cartesian2 b);
} // namespace usc::math

// functions to convert between primitive types
namespace usc::conv {
USC_DLL_EXPORT math::Polar Cartesian2ToPolar(math::Cartesian2 origin,
                                             math::Cartesian2 value);
USC_DLL_EXPORT math::Cartesian2 PolarToCartesian2(math::Cartesian2 origin,
                                                  math::Polar value);
} // namespace usc::conv
