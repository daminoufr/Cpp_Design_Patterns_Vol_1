#include <iostream>
#include <memory>

// wrapper: adapter

namespace Facade1
{
// first class to combine
class Interface_Not_Good { public:
  int* m_a;
  void set(int a) { m_a = new int(a); }
};
// second class to combine
class Interface_Not_Bad {
  int* m_b;
public:
  Interface_Not_Bad(int b) { m_b = new int(b); }
  int get() const { return *m_b; }
  ~Interface_Not_Bad() { delete m_b; }
};

// combination in Facade class
class Facade {
  Interface_Not_Good m_Not_Good;
  std::unique_ptr<Interface_Not_Bad> m_Not_Bad;
public:
  Facade(int a, int b) :
    m_Not_Bad(std::make_unique<Interface_Not_Bad>(b))  {
    m_Not_Good.m_a = new int(a);
  }
  int get() const { return *m_Not_Good.m_a+m_Not_Bad->get();}
  ~Facade() { delete m_Not_Good.m_a; }
};

int main() {
  Facade facade(3,5);
  std::cout << facade.get() << std::endl; // 8
  return 0;
}

}

int main_Facade1()
//int main()
{
  return Facade1::main();
}
