#include <iostream>
#include <string>
#include <vector>

// wrapper: Composite

namespace Composite1
{
// composite Interface
struct Interface { 
  virtual void show(const std::string& endl="\n") const = 0;
};

class Single : public Interface {
  int m_a;
public:
  Single(int a=0) : m_a(a) {}
  void show(const std::string& endl="\n") const override {
    std::cout << m_a << endl;
  }
};

class Collection : public Interface {
  // the collection is composed of multiple Single
  std::vector<Single> m_vec;
public:
  void add(const int& a) {
    m_vec.emplace_back(a);
  }
  void show(const std::string& endl="\n") const override {
    for(const Single& single: m_vec)
      single.show(",");
    std::cout << std::endl;
  }
};


// -------- main.cpp ----------------

int main() {
  Single single(4);
  single.show(); 
  Collection collection;
  collection.add(2);
  collection.add(4);
  collection.add(1);
  collection.show();

  return 0;
}

}

int main_compo()
{
  return Composite1::main();
}
