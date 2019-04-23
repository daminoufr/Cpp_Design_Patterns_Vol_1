//#include <iostream>
//#include <memory>
//
//namespace Builder3
//{
//  //Several builder types are possible
//  struct Builder {
//    virtual std::shared_ptr<Builder> clone() const = 0;
//  };
//  struct Builder1 : public Builder {
//    int m_b;
//    int m_c;
//    Builder1(int b, int c) : m_b(b), m_c(c) { }
//    std::shared_ptr<Builder> clone() const { return std::make_shared<Builder1>(*this); }
//  };
//  struct Builder2 : public Builder {
//    double m_d;
//    Builder2(int d) : m_d(d) { }
//    std::shared_ptr<Builder> clone() const { return std::make_shared<Builder2>(*this); }
//  };
//
//  Several products are possible
//    class Product {
//    public:
//      virtual std::string name() const = 0;
//      virtual double value() const = 0;
//      std::shared_ptr<const Builder> m_builder = NULL;
//  };
//  class Product1 : public Product {
//  public:
//    std::string name() const { return "Product1"; }
//    virtual double value() const { return m_a; }
//    int m_a;
//  };
//  class Product2 : public Product {
//  public:
//    std::string name() const { return "Product2"; }
//    virtual double value() const { return m_d1 + m_d2; }
//    double m_d1;
//    double m_d2;
//  };
//
//  Several Factories are possible
//    class AbstractFactory {
//    public:
//      virtual std::shared_ptr<Product> create(const std::shared_ptr<Builder>& builder) const = 0;
//  };
//  class Factory1 : public AbstractFactory {
//  public:
//    std::shared_ptr<Product> create(const std::shared_ptr<Builder>& builder)  const {
//      const std::shared_ptr<Builder1> builder1 = std::dynamic_pointer_cast<Builder1>(builder);
//      std::shared_ptr<Product1> product1 = std::make_shared<Product1>();
//      product1->m_a = builder1->m_b + builder1->m_c;
//      product1->m_builder = builder;
//      return product1;
//    };
//  };
//  class Factory2 : public AbstractFactory {
//  public:
//    std::shared_ptr<Product> create(const std::shared_ptr<Builder>& builder)  const {
//      const std::shared_ptr<Builder2> builder2 = std::dynamic_pointer_cast<Builder2>(builder);
//      std::shared_ptr<Product2> product2 = std::make_shared<Product2>();
//      product2->m_d1 = builder2->m_d;
//      product2->m_d2 = 10;
//      product2->m_builder = builder;
//      return product2;
//    };
//  };
//  We create the factories using this function
//    std::shared_ptr<AbstractFactory> create_Factory(const std::string& name)
//  {
//    if (name == "Factory1")
//      return std::make_shared<Factory1>();
//    else if (name == "Factory2")
//      return std::make_shared<Factory1>();
//    else
//      throw std::exception("Can't find the Factory");
//  }
//
//
//  int main() {
//
//    The factories are created first
//      std::shared_ptr<AbstractFactory> factory = create_Factory("Factory1");
//
//    The builder are not created in another part of the program
//      std::shared_ptr<Builder> builder = std::make_shared<Builder1>(2, 3);
//
//    The products are created using an already created factory
//      which will use the info from the builder
//      std::shared_ptr<Product> product = factory->create(builder);
//
//    show the value for this product
//      std::cout << "Product    : " << product->value() << std::endl;  // 5
//
//    return 0;
//  }
//
//
//}
//
