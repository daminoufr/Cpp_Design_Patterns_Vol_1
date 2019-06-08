#include <iostream>
#include <memory>
#include <deque>

namespace Command1
{
// all classes public to keep it simple 

// define a 'Command' interface
class Command { public:
  virtual void execute() const = 0;
};
// specialize Commands
class Command1 : public Command { public:
  virtual void execute() const {
    std::cout << "Command 1" << std::endl;
  }
};
class Command2 : public Command { public:
  virtual void execute() const {
    std::cout << "Command 2" << std::endl;
  }
};

// Collection of command
class Script {
  std::deque<std::shared_ptr<Command>> m_commands;
public:
  void push_back(const std::shared_ptr<Command>& command) {
    m_commands.push_back(command);
  }
  void execute() {
    while (!m_commands.empty())
    {
      // Execucute command First in - First out
      m_commands.front()->execute();
      // remove command when done
      m_commands.pop_front();
    }
  }
};


int main() {
  // Construct the collection of commands
  Script script;
  script.push_back(std::make_shared<Command1>());
  script.push_back(std::make_shared<Command2>());
  script.push_back(std::make_shared<Command2>());
  script.push_back(std::make_shared<Command2>());

  std::cout << "Script 'execute()':" << std::endl;
  script.execute();
  return 0;
}

}

int main_Command()
//int main()
{
  return Command1::main();
}
