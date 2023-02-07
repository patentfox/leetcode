#ifndef utils_h
#define utils_h
#include <iostream>

namespace myutils {
template <typename C>
void print(const C& cont) {
  for (auto x : cont) {
    std::cout << x << " ";
  }
  std::cout << std::endl;
}

}  // namespace myutils

#endif /* utils_h */
