#include <iostream>
#include <list>
#include <string>

namespace Mediator
{
// Mediator patter = Observer++

// Interface common to Clients and Mediator
// used to communicate between Clients and the Mediator
class Interface {
public:
  // Using string, but can be anything
  virtual void message_receive(const std::string& message) = 0;
  virtual void message_send(const std::string& message) = 0;
};

class Client : public Interface {
  // mediator address to send message 
  Interface* m_mediator = 0;
  // to know which client is called
  std::string m_numero;
public:
  Client(Interface* mediator, const std::string& numero) 
    : m_mediator(mediator), m_numero(numero) {}
  // receive the message and print result
  void message_receive(const std::string& message) {
    std::cout << "Client #" << m_numero << " update : "
      << message << std::endl;
  }
  // send message to mediator
  void message_send(const std::string& message) {
    std::string msg = "from client ";
    msg += m_numero;
    msg += ": ";
    msg += message;
    m_mediator->message_receive(msg);
  }
};

class Mediator : public Interface {
  // list of clients to dispatch the message
  std::list<Interface*> m_client;
public:
  Mediator() {}
  // attach clients
  void attach(Interface* client) {
    m_client.push_back(client);
  }
  void detach(Interface* client) {
    m_client.remove(client);
  }
  // receive a message from outside (could be a client)
  void message_receive(const std::string& message) {
    message_send(message);
  }
  // dispatch message to clients
  void message_send(const std::string& message) {
    std::string msg = "from mediator: ";
    msg += message;
    for (auto& client : m_client)
      client->message_receive(msg);
  }
};

int main() {
  Mediator mediator;

  Client* client_1(new Client(&mediator, "1"));
  Client* client_2(new Client(&mediator, "2"));
  Client* client_3(new Client(&mediator, "3"));

  // attach client to receive messages from the Mediator
  mediator.attach(client_2);
  mediator.attach(client_3);

  // send a message from the client to the mediator
  // the mediator will dispatch the message 
  client_1->message_send("tweet!");

  return 0;
}

}

int main_Mediator()
//int main()
{
  return Mediator::main();
}

