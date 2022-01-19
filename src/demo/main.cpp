// vk
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE
#include <glm/vec4.hpp>
#include <glm/mat4x4.hpp>

#include <iostream>
// usc
#include "usc/math/Vectors.hpp"
#include "usc/phys/Links.hpp"

int main() {
  namespace um = usc::math;
  namespace up = usc::phys;

  um::Vector2 vec_ola(um::Cartesian2{1, 3}, 4,
                      um::Angle{50, um::AngleType::Degrees});

  um::Vector2 vec_se(vec_ola.End(), um::Cartesian2{-5, 6});

  up::Link2 link(vec_ola, vec_se);

  link.PrintInfo();

  glfwInit();

  glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
  GLFWwindow* window = glfwCreateWindow(800, 600, "Vulkan window", nullptr, nullptr);

  uint32_t extensionCount = 0;
  vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, nullptr);

  std::cout << extensionCount << " extensions supported\n";

  glm::mat4 matrix;
  glm::vec4 vec;
  auto test = matrix * vec;

  while (!glfwWindowShouldClose(window)) {
    glfwPollEvents();
  }

  glfwDestroyWindow(window);

  glfwTerminate();

  return 0;
}
