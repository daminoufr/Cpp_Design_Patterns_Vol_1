#include <iostream>
#include <string>
#include <memory>


namespace F1
{
// define interface
class Product { public:
  virtual std::string name() const = 0;
};
// implementations
class Product1 : public Product { public:
  std::string name() const { return "Product1"; }
};
class Product2 : public Product { public:
  std::string name() const { return "Product2"; }
};

class Factory { 
  Factory() {}
public:
  // return a product depending of the input
  static std::shared_ptr<Product> 
    create(const std::string& name) {
    if (name == "Product1")
      return std::make_shared<Product1>();
    else if (name == "Product2")
      return std::make_shared<Product2>();
    else
      throw std::exception("Can't find product name");
  };
};

int main()
{
  std::shared_ptr<Product>  product = 
    Factory::create("Product2");
  std::cout << "Product    : " << product->name() 
    << std::endl;  // "Product2"
  return 0;
}

}

//int main()
int main_Fact1()
{
  return F1::main();
}
