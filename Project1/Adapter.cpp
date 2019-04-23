#include <iostream>
#include <memory>

// wrapper: adapter

namespace A1
{
class Interface_Not_Good { public:
  int* m_a;
  void set(int a) { m_a = new int(a); }
};

// Adapter class
class Interface_Good {
  Interface_Not_Good m_Not_Good;
public:
  Interface_Good(int a) {
    m_Not_Good.m_a = new int(a);
  }
  int get() const { return *m_Not_Good.m_a;  }
  ~Interface_Good() { delete m_Not_Good.m_a; }
};

int main() {
  Interface_Good interface_Good(3);
  std::cout << interface_Good.get() << std::endl; // 3
  return 0;
}

}

int main_A1()
{
  return A1::main();
}
