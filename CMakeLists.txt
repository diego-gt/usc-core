cmake_minimum_required(VERSION 3.20)

project(usc_core VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# To use with LSPs
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Library sections
set(MATH_HEADERS
	include/usc/math/Angle.hpp
	include/usc/math/Coordinates.hpp
	include/usc/math/Vectors.hpp
)

set(MATH_SOURCES
	src/math/Angle.cpp
	src/math/Coordinates.cpp
	src/math/Vectors.cpp
)

set(PHYSICS_HEADERS
	include/usc/phys/Links.hpp
)

set(PHYSICS_SOURCES
	src/phys/Links.cpp
)

set(TEXT_HEADERS
	include/usc/txt/Print.hpp
)

set(TEXT_SOURCES
	src/txt/Print.cpp
)

add_library(usc_core 
	${MATH_HEADERS}
	${MATH_SOURCES}
	${PHYSICS_HEADERS}
	${PHYSICS_SOURCES}
	${TEXT_HEADERS}
	${TEXT_SOURCES}
)

set(DEMO_SOURCES
	src/demo/main.cpp
)

find_package(glfw3 3.3 REQUIRED)
find_package(glm CONFIG REQUIRED)
find_package(Vulkan)

add_executable(usc_demo
	${DEMO_SOURCES}
)

target_include_directories(usc_core PUBLIC include)

target_include_directories(usc_demo PRIVATE ${Vulkan_INCLUDE_DIRS})
target_link_libraries(usc_demo PRIVATE usc_core)
target_link_libraries(usc_demo PRIVATE glfw)
target_link_libraries(usc_demo PRIVATE glm::glm)
target_link_libraries(usc_demo PRIVATE ${Vulkan_LIBRARY})

if (CMAKE_SYSTEM_NAME STREQUAL "Windows")
    target_compile_options(usc_core PRIVATE /W4)
elseif (CMAKE_SYSTEM_NAME STREQUAL "Linux")
    target_compile_options(usc_core PRIVATE -Wall -Wextra -Wpedantic)
    set(CMAKE_CXX_FLAGS "-stdlib=libc++")
endif ()
