#include <iostream>
#include <memory>

// decorator (type of wrapper)

namespace Deco1
{
// need a base class to have similar behavior
struct Base { 
  virtual ~Base() {};
};

// Original class
class Product : public Base{
  int m_a;
public:
  Product(int a) : m_a(a) {}
  int value() const { return m_a; }
};

// Decorator
// We want to add a new function value_new 
class Decorator : public Base {
  std::shared_ptr<Product> m_product;
  int m_add;
public:
  Decorator(int a, int add=0)
    : m_product(std::make_shared<Product>(a)), m_add(add) {}
  // re-implement all the Product interface
  int value() const { return m_product->value(); }
  // decorate the class with a new function
  int value_new() const { return m_product->value() + m_add; }
};

// print functions helper to have cleaner programs
template <typename T> void print(const T& t) {
  std::cout << t << std::endl;
}
template <typename T, typename... Args>
void print(const T& t, Args... args) {
  std::cout << t;
  print(args...);
}

int main() {
  Product product(4);
  print("Product(4).value=",product.value()); // 4
  Decorator decorator(4,5);
  print("Decorator(4,5).value=", decorator.value()); // 4
  print("Decorator(4,5).value_new=",decorator.value_new());//9
  return 0;
}

}

int main_Deco1()
{
  return Deco1::main();
}
