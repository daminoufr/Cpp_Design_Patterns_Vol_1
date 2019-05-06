#include <iostream>
#include <string>
#include <memory>

namespace AFB
{
struct BuilDetails {
  // to determine which factory to use
  // This info could be store in another place 
  std::string name;  
  // value used to construct the product
  int m_b;
  int m_c;
  BuilDetails(int b, int c) : m_b(b), m_c(c) { }
};

// create Product Families
class Product {  public:
  virtual std::string name() const = 0;
};
class Product1 : public Product {  public:
  int m_i;
  std::string name() const { return "Product1"; }

};
class Product2 : public Product {  public:
  double m_d1;
  double m_d2;
  std::string name() const { return "Product2"; }
};

// simple singleton
template <typename T>
std::shared_ptr<T> singleton() {
  static std::shared_ptr<T> instance = std::make_shared<T>();
  return instance;
}

// create Factory families
class AbstractFactory {  public:
  virtual std::shared_ptr<Product> create(
        const std::shared_ptr<BuilDetails>& builDetails) const = 0;
};
// do not include singleton here to simplify the code
class Factory1 : public AbstractFactory {  public:
  std::shared_ptr<Product> create(
        const std::shared_ptr<BuilDetails>& builDetails)  const {
    // create product1 from build details
    std::shared_ptr<Product1> product = std::make_shared<Product1>();
    product->m_i = builDetails->m_b + builDetails->m_c;
    return product;
  };
  static std::shared_ptr<Factory1> instance() { 
    return singleton<Factory1>(); }
};
class Factory2 : public AbstractFactory {  public:
  std::shared_ptr<Product> create(
        const std::shared_ptr<BuilDetails>& builDetails)  const {
    // create product2 from build details
    std::shared_ptr<Product2> product = std::make_shared<Product2>();
    product->m_d1 = builDetails->m_b;
    product->m_d2 = builDetails->m_c*2;
    return product;
  };
  static std::shared_ptr<Factory2> instance() { 
    return singleton<Factory2>(); }
};

// create Factory from name
std::shared_ptr<AbstractFactory> createFactory(
      const std::shared_ptr<BuilDetails>& builDetails) {
  if (builDetails->name == "Factory1")
    return Factory1::instance();
  else if (builDetails->name == "Factory2")
    return Factory2::instance();
  else
    throw std::exception("Can't find factory name");
}
// help function to create product from build details
std::shared_ptr<Product> createProduct(
      const std::shared_ptr<BuilDetails>& builDetails) {
  return createFactory(builDetails)->create(builDetails);
}

int main() {
  // create the build details and  the product
  std::shared_ptr<BuilDetails> builDetails
    = std::make_shared<BuilDetails>(2, 3);
  builDetails->name = "Factory2";

  // create the product from the build details
  std::shared_ptr<Product> product = createProduct(builDetails);

  // check
  std::cout << product->name() << std::endl;  // Product2

  return 0;
}

}

int main_AFB()
//int main()
{
  return AFB::main();
}
