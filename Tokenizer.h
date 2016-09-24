#include <string>
#include <sstream>
#include <list>
#include <iostream>
#include <assert.h>

using namespace std;


typedef struct Tokenized {
  string m_command;
  string m_package;
  list<string> m_dependencies;
} Tokenized_t;


class Tokenizer
{
  string m_unparsed;
  Tokenized_t m_tokenized;

private:

  static void split(string input, char delim, list<string> *items) {
    istringstream ss(input);
    string token;

    while(std::getline(ss, token, delim)) {
      items->push_back(token);
    }
  }
    
  /**
   * unparsed string is defined as such:
   * <command>|<package>|<dependencies>\n
   * Where <command> and <package> are a single string and
   * <dependencies> is a comma delimeted list.
   * The tokenize method will perform the following:
   * 1) verify input is valid
   * 2) split items by '|' delimeter - will always produce three strings, when valid
   * 3) ensure mandatory fields are present
   * 4) split, if optional dependencies are present, dependencies into a list, using comma as a delimeter.
   *
   * tokenized result is return
   * nullptr returned on parsing error
   */
  void tokenize() {
    list<string> items;
    split(m_unparsed, '|', &items);

    if (items.size() != 3) {
#ifndef NDEBUG
      cout << "Expected three tokens, got " << items.size() << endl;
#endif	/* NDEBUG */
      return;
    }

    m_tokenized.m_command = items.front();
    items.pop_front();
    m_tokenized.m_package = items.front();
    items.pop_front();

    string depends(items.front());
    items.pop_front();
    // a newline character is expected as the last character
    if (depends.back() != '\n') {
      m_tokenized.m_command = ""; // clear out the results and return;
      m_tokenized.m_package = ""; // clear out the results and return;
#ifndef NDEBUG
      cout << "Expected newline is missing at end of string: " << depends << endl;
#endif	/* !NDEBUG */
      return;
    } else {
      // remove newline character
      depends.pop_back();
    }

    split(depends, ',', &m_tokenized.m_dependencies);
  }

public:

  Tokenizer(string input) : m_unparsed(input) {
    m_tokenized.m_command = "";
    tokenize();
  }

  Tokenized_t *getTokenized() {
    if (m_tokenized.m_command == "") {
      return nullptr;
    }
    return &m_tokenized;
  }

};
  
  
