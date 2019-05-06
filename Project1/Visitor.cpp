#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include <iostream>

namespace Visitor
{
// forward declaration of Objects
class Object_A;
class Object_B;

// Interface to be able to create a new visitor
// without the need to change this base class
class Visitor { public:
  // one visitor by object type
  virtual void visit(Object_A* a) = 0;
  virtual void visit(Object_B* b) = 0;
};

// Base class for Objects
class Object {
public:
  // to be able to visit the class
  virtual void accept(Visitor* v) = 0;
};

class Object_A : public Object { public:
  int m_number = 0;
  void accept(Visitor* v) {
    // send this object to visitor
    v->visit(this);
  }
};
class Object_B : public Object { public:
  double m_d1 = 9;
  double m_d2 = 3;
  void accept(Visitor* v) {
    // send this object to visitor
    v->visit(this);
  }
};

class Visitor_Imp: public Visitor { public:
  void visit(Object_A* a) {
    // use the public interface of Object A 
    std::cout << "A: " << a->m_number << std::endl;
  }
  void visit(Object_B* b) {
    // use the public interface of Object B 
    std::cout << "B: " <<b->m_d1<<"-"<<b->m_d2<<std::endl;
  }
};


int main() {
  // create objects
  Object_A object_A;
  Object_B object_B;

  // create visitor... and visit the objects
  Visitor_Imp v;
  object_A.accept(&v);
  object_B.accept(&v);

  return 0;
}

}

int main_Visitor()
{
  return Visitor::main();
}

