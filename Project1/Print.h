#pragma once

// print functions helper to have cleaner programs
template <typename T> void print(const T& t) {
  std::cout << t << std::endl;
}
template <typename T, typename... Args>
void print(const T& t, Args... args) {
  std::cout << t;
  print(args...);
}

