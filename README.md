# usc-core

# USC library
Core library to be used in all USC projects, mainly ones regarding the Calvin system.

## Building the library
TODO

## Structure
If a header file has a singular name like `Angle.hpp`, it means that it should only have one main data type and helper functions regarding that type.  
On the other side, if a header file has a plural name like `Coordinates.hpp`, it means that it stored multiple data types that are related to `title`. In the example, that header contains `Cartesian2`, a type meant to represent a point in a 2D cartesian coordinate system, as well as `Cartesian3` that it's similar just implemented to handle a 3D coordinate system.

Only headers in the `include` directory are exposed to projects using this as a library. Anything in `src` is meant to be private to the library.

The library is trying to be dependency-free, so everything is developed in house and no 3rd party code is used besides the standard library.
This means that everything may not be as efficient as an experienced developer could make it to be, but it's meant to be worked on by the team and get experience.

Each section of the library is contained in a directory that should somewhat describe what to expect from the section. Inside the code, there's namespaces that are the same as the section name. There's a global namespace called `usc` that is the parent to all other namespaces. Everything in this library should be in this namespace.
An example will be:

> You want to use the `Angle` data type in your project.
After configuring your project, you would include the header in the compilation unit like so:
```cpp
#include "usc/math/Angle.hpp
```
And you would use it in your code like this:
```cpp
usc::math::Angle GetAngle();
```

## Formatting
We use the standard LLVM style guide that clang-format (v. 10.0.0) provides. Please use this with clang-format to apply any formatting.
Remember to format your code before pushing a commit to the repo.

## Naming conventions
We will use mostly PascalCase in everything that's directly related to the code.
Exceptions to this are:
- Code namespaces. i.e. All the code regarding Math is inside the namespace `usc::math`.
- Directories inside `include` that are meant to be the same as the namespaces in the code.
- Private class members. We are using the convention `m_<name>` for these.
- Struct members. i.e. the `struct` Polar has two members: `radius` and `theta`.

That leave us to use PascalCase in:
- Files.
- Functions.
- Classes and structs
- Class methods.

## Data types: Headers and compilation units

We use the _compilation unit_ concept to refer to a `.cpp` file.  
When creating a new data type (either a `struct` or `class`), create two files: a _header_ file and a _compilation unit_ file.  
- Header file should have a `.hpp` extension. (This may change in the future, but please be consistent with the current standard. If we decide to make a change, it should be change throughout all the project).
- Compilation file should have a `.cpp` extension.

Only provide method and function definitions or prototypes in the header file.  
Provide all the implementation details in the compilation unit.  
This means that if you create a new, let's say, section of the library that is meant to handle printing text to the stdout you'd follow this:  
Since this is part of the library functionality, we want to make it public, so the header file will be inside the `include` directory. 
Compilation file can be in the `src` directory. So you'd have this directory structure:
```
include/
    usc/
        txt/
            PrintText.hpp
src/
    txt/ (optional)
        PrintText.cpp
```

In `PrintText.hpp`:
```cpp
#pragma once
#include <string>
namespace usc::txt {
    void PrintText(const std::string& message);
}
```

In `PrintText.cpp`:
```cpp
#include "usc/txt/PrintText.hpp"
#include <iostream>
namespace usc::txt {
    void PrintText(const std::string& message) {
        std::cout << message << "\n";
    }
}
```

## Contents
- Math
    - Angle: Data type to handle angles in general, stores its value in radians and degrees.
    - Coordinates: Set of data types (`Cartesian2`, `Cartesian3`, `Polar`) that are meant to be used in a coordinate system.
        - TODO: Implement Cartesian3, Circular, more 3D support
    - Vectors: Set of data types meant to represent the standard linear algebra vectors (i.e. They have an angle (direction), length, origin and end point). Currently only Vector2 is being developed.
        - TODO: Implement Vector3
- Physics
    - Links: Data types that represent a link between vectors. 
- Text