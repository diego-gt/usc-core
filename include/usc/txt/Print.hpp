#pragma once

#include "usc/Visibility.hpp"

#include <string>

namespace usc::txt {
// Prints a message to stdout ending with an ending newline
USC_DLL_EXPORT void Println(const std::string &message);

// Prints a message to stdout
USC_DLL_EXPORT void Print(const std::string &message);

// Print a message with a tab at the beginning
USC_DLL_EXPORT void TabPrintln(const std::string &message);
} // namespace usc::txt