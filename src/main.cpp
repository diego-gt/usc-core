#include "usc/math/Vectors.hpp"
#include "usc/phys/Links.hpp"
#include "usc/txt/Print.hpp"

int main() {
  namespace um = usc::math;
  namespace ut = usc::txt;
  namespace up = usc::phys;

  um::Vector2 vec_ola(um::Cartesian2{1, 3}, 4,
                      um::Angle{50, um::AngleType::Degrees});

  um::Vector2 vec_se(vec_ola.End(), um::Cartesian2{-5, 6});

  up::Link2 link(vec_ola, vec_se);

  link.PrintInfo();

  return 0;
}
