cmake_minimum_required(VERSION 3.20)

project(usc_core VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# To use with LSPs
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_library(usc_core 
	include/usc/math/Angle.hpp src/math/Angle.cpp
	include/usc/math/Coordinates.hpp src/math/Coordinates.cpp
	include/usc/math/Vectors.hpp src/math/Vectors.cpp
	include/usc/phys/Links.hpp src/phys/Links.cpp
	include/usc/txt/Print.hpp src/txt/Print.cpp
	)

add_executable(usc_demo 
	src/demo/main.cpp)

target_include_directories(usc_core PUBLIC include)

target_link_libraries(usc_demo PRIVATE usc_core)

if (CMAKE_SYSTEM_NAME STREQUAL "Windows")
    target_compile_options(usc_core PRIVATE /W4)
elseif (CMAKE_SYSTEM_NAME STREQUAL "Linux")
    target_compile_options(usc_core PRIVATE -Wall -Wextra -Wpedantic)
    set(CMAKE_CXX_FLAGS "-stdlib=libc++")
endif ()
