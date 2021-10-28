#pragma once

#include "usc/Visibility.hpp"
#include "usc/math/Vectors.hpp"

namespace usc::phys {
class USC_DLL_EXPORT Link2 {
private:
  math::Vector2 m_tail, m_head;

public:
  Link2(math::Vector2 &tail, math::Vector2 &head);

  void PrintInfo();

  math::Cartesian2 Endpoint() { return m_head.End(); }
};
} // namespace usc::phys