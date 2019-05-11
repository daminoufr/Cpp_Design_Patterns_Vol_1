#include <iostream>
#include <memory>

namespace P1
{
// -------- Interface.h --------------
// interface.h you give to your clients 
class Interface { 
  // forward declaration of Implementation class
  class Implementation; // implemented in cpp

  // you declare a pointer, no need to give
  // the implementation interface
  std::unique_ptr<Implementation> m_pimpl;
public:
  Interface();       // implemented in cpp
  int value() const; // implemented in cpp
};

// -------- Interface.cpp ------------

// implementation class 
class Interface::Implementation
{
  int m_a = 0;   // you can have 
public:
  void setValue(int a) { m_a = a; }
  int value() const { return m_a; }
};

// Inteface implementation --
Interface::Interface() : m_pimpl(
  std::make_unique<Interface::Implementation>()) 
{
  m_pimpl->setValue(10);
}
int Interface::value() const {
  // here you use the pointer implementation
  // this is hiden from your clients
  return m_pimpl->value();
}

// -------- main.cpp ----------------

int main() {
  Interface interface;
  std::cout << interface.value() << std::endl; // 10
  return 0;
}

}

int main_Pimpl()
//int main()
{
  return P1::main();
}
