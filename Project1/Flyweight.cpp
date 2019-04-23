#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <memory>
#include <windows.h> // remove this on linux

namespace FW
{

// the intrinsic class which can be shared
class Character {
  char m_char;
  // array of pixel 100*100
  std::vector<bool> m_pixels 
    = std::vector<bool>(10000);
public:
  Character(const char& char_) : m_char(char_) {
    // TODO: initalize the array for the char
  }
  void display(const unsigned short& color) const {
    // should display the pixels (m_pixels) 
    // with the color given
    // for testing, just display the char

    // windows only for next two lines
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);

    std::cout << m_char;
  }
};

// The Factory to store the letters
class Factory {
  // map : storage for the char->Letter
  std::map<char, std::shared_ptr<Character>> m_character;
public:
  // singleton
  static std::shared_ptr<Factory> instance() {
    static std::shared_ptr<Factory> instance 
      = std::make_shared<Factory>();
    return instance;
  }
  // get Character, static way
  static std::shared_ptr<Character> getLetter(char char_) {
    return instance()->get(char_);
  }
  // get Character, lazzy way
  std::shared_ptr<Character> get(char char_) {
    // have we stored the Character?
    auto iter = m_character.find(char_);
    // if found -> return stored
    if (iter != m_character.end())
      return iter->second;
    // else add to storage
    std::shared_ptr<Character> character 
      = std::make_shared<Character>(char_);
    m_character[char_] = character;
    return character;
  }
};

// Class Letter wich include the color (extrinsic)
class Letter {
  unsigned short m_color; // extrinsic
  std::shared_ptr<Character> m_chararcter; // intrinsic
public:
  Letter(char char_, const unsigned short& color) : 
    m_color(color),
    m_chararcter(Factory::getLetter(char_)) {}
  void display() const {
    // display forwarded to the Character class
    m_chararcter->display(m_color);
  }
};

// Class text
class Text {
  std::vector<Letter> m_letters;
public:
  // adding letters 
  void add_Letters(const std::string& text, 
    const unsigned short& color) {
      for(const char c: text)
        m_letters.emplace_back(c, color);
  }
  // display forwarded to the Letter class
  void display() const {
    for (const Letter& letter : m_letters)
      letter.display();
  }
};

int main() {
  Text text;
  text.add_Letters("ababa", 12); // 12=red
  text.add_Letters("fgggf", 9);  // 9=blue
  text.display();
  return 0;
}

}

int main_FW()
{
  return FW::main();
}
