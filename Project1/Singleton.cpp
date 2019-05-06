#include <iostream>
#include <memory>

namespace S1
{
// the class to have only one instance
class Factory { 
  // can't create instance directly
  Factory() { 
    std::cout << "Factory created" << std::endl;
  }
public:
  static std::shared_ptr<Factory> instance() {
    // only one instance will be created the first time 
    static std::shared_ptr<Factory> instance(new Factory());
    return instance;
  }
};

int main() {
  std::shared_ptr<Factory> factory = Factory::instance();
  return 0;
}

}

//int main()
int main_Sing()
{
  return S1::main();
}
