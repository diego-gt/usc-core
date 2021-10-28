#include "usc/txt/Print.hpp"

#include <iostream>

namespace usc::txt {
void Println(const std::string &message) { std::cout << message << "\n"; }
void Print(const std::string &message) { std::cout << message; }

void TabPrintln(const std::string &message) {
  std::cout << "\t" << message << "\n";
}
} // namespace usc::txt