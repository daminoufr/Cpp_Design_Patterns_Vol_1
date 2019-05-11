#include <iostream>
#include <memory>

namespace Builder2
{
// calculate risk = product_updated value - product value  

struct BuilDetails {
  int m_b;
  int m_c;
  BuilDetails(int b, int c) : m_b(b), m_c(c) { }
  // need a clone, if we need to recreate 
  std::shared_ptr<BuilDetails> clone() const { 
    return std::make_shared<BuilDetails>(*this); }
};

class Product {
public:
  int m_a;
  // keep the buildDetails in the product
  std::shared_ptr<const BuilDetails> m_builDetails = NULL;
};

class Factory {
public:
  static std::shared_ptr<Product> 
    create(const std::shared_ptr<BuilDetails>& builDetails) {
    // create the product from the build details
    std::shared_ptr<Product> product = std::make_shared<Product>();
    product->m_a = builDetails->m_b + builDetails->m_c;
    // add the build details to the product
    product->m_builDetails = builDetails;
    return product;
  };
};

int main() {

  // create the build details and  the product
  std::shared_ptr<BuilDetails> builDetails 
    = std::make_shared<BuilDetails>(2, 3);
  std::shared_ptr<Product> product 
    = Factory::create(builDetails);

  // calculate the 'risk'
  // clone the builDetails
  std::shared_ptr<BuilDetails> builDetails_cloned 
    = builDetails->clone();
  // update the cloned builDetails
  builDetails_cloned->m_b += 1;
  // create a new product
  std::shared_ptr<Product> product2 
    = Factory::create(builDetails_cloned);
  // calculate the 'risk'
  std::cout << "Product        : " 
    << product->m_a << std::endl;  // 5
  std::cout << "Product_updated: " 
    << product2->m_a << std::endl;  // 6
  std::cout << "Risk           : " 
    << product2->m_a - product->m_a << std::endl;  // 1

  return 0;
}

}

int main_Builder2()
//int main()
{
  return Builder2::main();
}

