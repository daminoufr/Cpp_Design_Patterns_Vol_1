#include <iostream>
#include <vector>
#include <string>

namespace Memento2
{
// saving data class
struct Memento { 
  int m_number; 
  Memento(int number) : m_number(number) {}
};

// collection of Memento: undo - redo
struct Records {
  // the stack records of mementos
  std::vector<const Memento*> m_mementos;
  // where we are in the stack
  int m_pos = -1;
  // adding a new elements
  void add(const Memento* memento) {
    if (m_pos + 1 == m_mementos.size())
    {
      // adding at the end
      m_mementos.push_back(memento);
      ++m_pos;
    }
    else
    {
      // adding in the middle, after some undo
      m_mementos[++m_pos] = memento;
      m_mementos.resize(m_pos + 1);
    }
  }
  const Memento* undo() {
    if (m_pos == 0)
      // only one element
      return m_mementos[0];
    return m_mementos[--m_pos];
  }
  const Memento* redo() {
    if (m_pos + 1 == m_mementos.size())
      // only one element
      return m_mementos.back();
    else
      return m_mementos[++m_pos];
  }
  // help : show the current stack
  void print() const {
    std::cout << "{ ";
    for (size_t i = 0; i < m_mementos.size(); ++i) {
      // if undo, some elements are not displayed
      if (i > m_pos) std::cout <<  "(";
      std::cout << m_mementos[i]->m_number;
      if (i > m_pos) std::cout << ")";
      if (i + 1 != m_mementos.size()) std::cout << ", ";
    }
    std::cout << " }";
  }
};

class Object { 
  int m_number = 0;
  // Record: collection of memento, to help undo/redo
  Records m_Records;
  //Memento: create from/to
  Memento* create_Memento() const {
    return new Memento(m_number);
  }
  void set_Memento(const Memento* memento) {
    m_number = memento->m_number;
  }
public:
  Object() {
    // add first record when created
    m_Records.add(create_Memento());
  }
  void update(int num) { 
    m_number += num;
    // each update is saved
    m_Records.add(create_Memento());
  }
  void undo() {
    set_Memento(m_Records.undo());
  }
  void redo() {
    set_Memento(m_Records.redo());
  }
  // help debug
  void print(const std::string& msg) {
    std::cout << msg;
    std::cout << m_number << "   // ";
    // show saved Mementos:
    m_Records.print();
    std::cout << std::endl;
  }
};

int main() {
  
  Object object; // {0}
  object.print("start   : ");
  for (int i = 1; i < 6; ++i)
  {
    object.update(1); 
    object.print("update  : ");
  }                    // { 0, 1, 2, 3, 4, 5}
  object.redo(); // no effect
  object.print("redo    : ");
  object.undo();      // { 0, 1, 2, 3, 4, (5) }
  object.print("undo    : ");
  object.undo();      // { 0, 1, 2, 3, (4), (5) } 
  object.print("undo    : ");
  object.redo();   // { 0, 1, 2, 3, 4, (5) }
  object.print("redo    : ");
  object.undo();      // { 0, 1, 2, 3, (4), (5) }
  object.print("undo    : ");
  object.update(5);   // { 0, 1, 2, 3, 8 }
  object.print("update  : ");
  object.redo();   // { 0, 1, 2, 3, 8 }
  object.print("redo    : ");
  object.undo();      // { 0, 1, 2, 3, (8) }
  object.print("undo    : ");
  object.undo();      // { 0, 1, 2, (3), (8) }
  object.print("undo    : ");
  object.undo();      // { 0, 1, (2), (3), (8) }
  object.print("undo    : ");
  object.undo();      // { 0, (1), (2), (3), (8) }
  object.print("undo    : ");
  object.undo();      // { 0, (1), (2), (3), (8) }
  object.print("undo    : ");

  return 0;
}

}

int main_Memento2()
//int main()
{
  return Memento2::main();
}

