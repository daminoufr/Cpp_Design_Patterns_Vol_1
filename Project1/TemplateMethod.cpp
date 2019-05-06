#include <iostream>

namespace TemplateMethod
{
class TemplateMethod {
  // private method which can be overridden
  virtual void operation1() const {
    std::cout << "operation1 base" << std::endl;
  }
  virtual void operation2() const {
    std::cout << "operation2 base" << std::endl;
  }
public:
  // non virtual function only interface
  void apply() const {
    // call virtual functions
    operation1();
    operation2();
  }
};
// define derived class with overriding some virtual functions
class TemplateMethod_A : public TemplateMethod {
  virtual void operation2() const override {
    std::cout << "operation2 Impl A" << std::endl;
  }
};
class TemplateMethod_B : public TemplateMethod {
  virtual void operation2() const override {
    std::cout << "operation2 Impl B" << std::endl;
  }
};


int main() {
  TemplateMethod_A method_A;
  TemplateMethod_B method_B;

  method_A.apply();
  method_B.apply();
  return 0;
}

}

int main_TemplateMethod()
//int main()
{
  return TemplateMethod::main();
}

