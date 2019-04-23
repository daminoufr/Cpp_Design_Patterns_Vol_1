
#include <iostream>
#include <memory>

namespace S1
{
// print functions helper to have cleaner programs
template <typename T> void print(const T& t) {
  std::cout << t << std::endl;
}
template <typename T, typename... Args> 
void print(const T& t, Args... args) {
  std::cout << t ;
  print(args...);
}

// the singleton template
template <typename T>
std::shared_ptr<T> singleton() {
  static std::shared_ptr<T> instance = std::make_shared<T>();
  return instance;
}

// the class to have only one instance
class Factory { public:
  int m_count = 0;
  Factory() { ++m_count; }
  static std::shared_ptr<Factory> instance() {
    return singleton<Factory>();
  }
};

int main() {
  print("m_count=", Factory::instance()->m_count);
  print("m_count=", Factory::instance()->m_count);
  print("m_count=", Factory::instance()->m_count);
  return 0;
}

}

//int main()
//{
//  return S1::main();
//}
