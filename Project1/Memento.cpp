#include <iostream>

namespace Memento1
{
struct Memento { 
  // data used to re-create the Object
  int m_number; 
  Memento(int number) : m_number(number) {}
};

class Object { 
  // only data to be re-created
  int m_number = 0;
public:
  // interface to do 'something' 
  int get() const { return m_number;  }
  void update() { ++m_number; }
  // get Mememto 
  Memento* create_Memento() const {
    return new Memento(m_number);
  }
  // re-create from Memento
  void set_Memento(const Memento* memento) {
    m_number = memento->m_number;
  }
};

int main() {
  
  Object object;
  object.update();  
  // check point
  Memento* memento1 = object.create_Memento();
  std::cout << "memento at: " << object.get() << std::endl;
  // do something
  object.update();
  object.update();
  std::cout << "before set: " << object.get() << std::endl;
  // return to the check point
  object.set_Memento(memento1);
  std::cout << "after  set: " << object.get() << std::endl;

  return 0;
}

}

int main_Memento1()
//int main()
{
  return Memento1::main();
}

