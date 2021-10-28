#pragma once

#include "usc/Visibility.hpp"
#include "usc/math/Angle.hpp"
#include "usc/math/Coordinates.hpp"

// Vectors impl
namespace usc::math {
class USC_DLL_EXPORT Vector2 {
private:
  Cartesian2 m_start{0, 0}, m_end{0, 0};
  double m_length{0};
  Angle m_angle{0, AngleType::Degrees};

public:
  // Print debug info
  void PrintInfo();

  Vector2() = default;

  // Create a vector using two points
  Vector2(Cartesian2 start, Cartesian2 end);

  // Using an origin, length and angle from the horizontal axis
  Vector2(Cartesian2 origin, double length, Angle angle);

  // Get the starting point of the vector
  Cartesian2 Origin() { return m_start; }

  // Get the end point of the vector
  Cartesian2 End() { return m_end; }

  // Get the current length of the vector
  double Length() { return m_length; }

  // RENAME: Angle is reserved, what other general term could we use? rotation?
  // direction? Get the current angle value. To get degrees or radians, call the
  // result with .Degrees() or .Radians()
  Angle Theta() { return m_angle; }

  // Change the rotation angle of the vector to a given angle
  void RotateTo(Angle angle);

  // Rotate vector by value
  void Rotate(double rotation, AngleType at);

  // Change the current length of the vector
  void Resize(double length);

  // Change the origin of the vector
  void Translate(Cartesian2 origin);
};
} // namespace usc::math