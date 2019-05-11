#include <iostream>
#include <memory>

namespace B1
{
// -------- Interface.h --------------
// interface.h you give to your clients 

// forward declaration of Implementation class
class Implementation; // implemented in cpp

class Interface {
protected:
  // you declare a pointer, no need to give
  // the implementation interface
  std::unique_ptr<Implementation> m_pimpl;
public:
  virtual int value() const = 0;
};

// derived classes from Interface
class Interface_derived_1: public Interface {
public:
  Interface_derived_1();     // implemented in cpp
  int value() const;         // implemented in cpp
};
class Interface_derived_2: public Interface {
public:
  Interface_derived_2();     // implemented in cpp
  int value() const;         // implemented in cpp
};

// -------- Interface.cpp ------------

// implementation classes ---- 
class Implementation { public:
  virtual int value() const = 0;
};
// derived classes from Implementation 
// these will be initialized by the Interface_derived classes
class Implementation_derived_1 : public Implementation
{
  int m_a = 0;
public:
  Implementation_derived_1(int a) { m_a = a; }
  int value() const { return m_a; }
};
class Implementation_derived_2 : public Implementation
{
  double m_d1 = 0.;
  double m_d2 = 0.;
public:
  Implementation_derived_2(double d1, double d2)
    : m_d1(d1), m_d2(d2) { }
  int value() const { return (int)(m_d1+m_d2); }
};


// Inteface implementation ---
Interface_derived_1::Interface_derived_1() {
  m_pimpl = std::make_unique<Implementation_derived_1>(3);
}
int Interface_derived_1::value() const {
  // here you use the pointer implementation
  // this is hiden from your clients
  return m_pimpl->value();
}
Interface_derived_2::Interface_derived_2() {
  m_pimpl = std::make_unique<Implementation_derived_2>(1.,4.);
}
int Interface_derived_2::value() const {
  // here you use the pointer implementation
  // this is hiden from your clients
  return m_pimpl->value();
}

// -------- main.cpp ----------------

// print functions helper to have cleaner programs
template <typename T1>
void print(const T1& t1) {
  std::cout << t1 << std::endl;
}


int main() {
  Interface_derived_1 interface_1;
  Interface_derived_2 interface_2;

  print(interface_1.value()); // 3
  print(interface_2.value()); // 5
  return 0;
}

}

int main_Bridge()
//int main()
{
  return B1::main();
}
