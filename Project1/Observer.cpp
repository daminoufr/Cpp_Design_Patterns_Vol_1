#include <iostream>
#include <list>
#include <string>

namespace Observer
{

// abstract class with the interface
class Observer {
public:
  // we send a string but can be anything else
  virtual void update(const std::string& message) = 0;
};

// one implementation of the Observer class
class Observer_Imp: public Observer {
  int m_numero;
public:
  Observer_Imp(int numero) : m_numero(numero) {}
  // here just display 
  void update(const std::string& message) {
    std::cout<<"Observer #"<<m_numero<< " update : "
      << message <<std::endl;
    }
};

// You can define other implementation 
// class Observer_Imp_Other: public Observer {


class Subject {
  // collection of observer
  std::list<Observer*> m_observers;
public:
  Subject() {}
  // can attach and detach at run time
  void attach(Observer* observer) {
    m_observers.push_back(observer);
  }
  void detach(Observer* observer) {
    m_observers.remove(observer);
  }
  // will call all attached observers 
  void notify() {
    for (auto& observer : m_observers)
      observer->update("from subject");
  }
};

int main() {
  // Create two observers
  Observer_Imp* observer_1(new Observer_Imp(1));
  Observer_Imp* observer_2(new Observer_Imp(2));

  Subject subject;
  // attach observers at run time
  subject.attach(observer_1);
  subject.attach(observer_2);
  // send notification to observers
  subject.notify();

  return 0;
}

}

int main_Obs()
//int main()
{
  return Observer::main();
}

