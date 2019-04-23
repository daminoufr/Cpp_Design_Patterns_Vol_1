#include <iostream>
#include <map>
#include <vector>
#include <memory>

namespace Proxy
{

// the intrinsic class which can be shared
class Character {
  char m_char;
  // array of pixel 100*100
  std::vector<bool> m_pixels
    = std::vector<bool>(10000);
public:
  Character(const char& char_): m_char(char_) {
    std::cout << "Character Pixels created for "
      << char_<< std::endl;
  }
  const std::vector<bool>& get() const { return m_pixels; }
};

class Letter {
  // Proxy
  char m_char;
  std::shared_ptr<Character> m_chararcter; 
public:
  // Lazy: Character is not initalized
  Letter(char char_) : m_char(char_) {}
  // we need the Character pixels to display it
  const std::vector<bool>& get() {
    if (!m_chararcter) // Lazy
      m_chararcter = std::make_shared<Character>(m_char);
    return m_chararcter->get();
  }
  // for const object
  const std::vector<bool>& get() const {
    // ouch: need it for lazy
    return const_cast<Letter*>(this)->get();
  }
};

int main() {
  // create the letters from 'a' to 'z', 
  // and save them in the map
  std::map<char, std::shared_ptr<Letter>> letters_auth;
  for (size_t i = 0; i < 26; ++i)
  {
    char c = (char)('a' + i);
    letters_auth[c] = std::make_shared<Letter>(c);
  }

  // The pixels array will be created only 
  // for the following letters
  letters_auth['l']->get();
  letters_auth['a']->get();
  letters_auth['a']->get();
  letters_auth['a']->get();
  letters_auth['z']->get();
  letters_auth['y']->get();
  return 0;
}

}

int main()
{
  return Proxy::main();
}
