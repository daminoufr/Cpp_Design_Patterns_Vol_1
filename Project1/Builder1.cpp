#include <iostream>
#include <memory>

namespace Builder1
{
// all public to keep a simple code

struct BuilDetails {
  int m_b;
  int m_c;
  BuilDetails(int b, int c) : m_b(b), m_c(c) { }
};

class Product {
public:
  int m_a;
};

class Factory {
  Factory() {}
public:
  static std::shared_ptr<Product> create(const BuilDetails& builDetails) {
    // create the product from the build details
    std::shared_ptr<Product> product = std::make_shared<Product>();
    product->m_a = builDetails.m_b + builDetails.m_c;
    return product;
  };
};

int main() {
  // create the build details
  BuilDetails builDetails(2, 3);
  // create the product
  std::shared_ptr<Product> product = Factory::create(builDetails);
  std::cout << product->m_a << std::endl;  // 5
  return 0;
}

}

int main_Builder1()
//int main()
{
  return Builder1::main();
}
