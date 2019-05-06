#include <iostream>

namespace State
{
// points of convergences with 'Chain of responsability' 
// Same as strategy

// Class Handler: we derive two type of handler  
class Handler { public:
  virtual void apply(int number) const = 0;
};
class Handler1 : public Handler { public:
  void apply(int number) const {
    std::cout << "Handler1 :" << 2 * number << std::endl;
  }
};
class Handler2 : public Handler { public:
  void apply(int number) const {
    std::cout << "Handler2 :" << number+1 << std::endl;
  }
};

// Class Object which will be handled by the handlers
class Object { 
  int m_number = 0;
  // The state
  const Handler* m_state = 0;
public:
  Object(int number) : m_number(number) {}
  void set_state(const Handler* state) {
    m_state = state;
  }
  void execute() {
    // call the handler
    m_state->apply(m_number);
  }
};



int main() {
  Object object(3);
  // set the hanlder and apply
  object.set_state(new Handler1());
  object.execute();
  // set the hanlder and apply
  object.set_state(new Handler2());
  object.execute();

  return 0;
}

}

//int main_State()
int main()
{
  return State::main();
}

