#include <iostream>

namespace Chain
{
  // A client with a number.
  // we want to update the m_result by the handlers
  class Client { public:
    int m_number;
    int m_result = -1;
    Client(int number) : m_number(number) {}
};

class Handler { public:
  virtual void add(Handler* handler) = 0;
  virtual Client& apply(Client& client) const = 0;
};

class Handler_Imp : public Handler {
  // chain of responsability: if we can't update 
  // the result in this handler, pass to the next Handler
  Handler* m_handler = 0;
  // used for the handling condition
  int m_numero;
 public:
  Handler_Imp(int numero): m_numero(numero) {}
  // adding chain of handler
  void add(Handler* handler) {
    if (m_handler)
      // handler already present, pass to next
      m_handler->add(handler);
    else
      m_handler = handler;
  }
  Client& apply(Client& client) const
  {
    if (client.m_number%m_numero == 0)
    {
      // update result on this handler
      client.m_result = 10 * m_numero;
      return client;
    }
    else if(m_handler)
      // pass to next handler, if possible
      return m_handler->apply(client);
    return client;
  }
};

int main() {
  // create handlers
  Handler_Imp handler2(2);
  Handler_Imp handler3(3);
  Handler_Imp handler5(5);

  // create the chain of responsability
  handler2.add(&handler3);
  handler2.add(&handler5);

  // lambda used to calculate and display result
  auto Result = [](const Handler& handler,  int num) {
    std::cout << "Result for Client(" << num << "): " 
      << handler.apply(Client(num)).m_result << std::endl;
  };

  // Apply chain of handler for several clients
  Result(handler2, 81);
  Result(handler2, 80);
  Result(handler2, 17);
  Result(handler2, 25);

  return 0;
}

}

int main_chain()
//int main()
{
  return Chain::main();
}

