#include <string>
#include <sstream>
#include <vector>
#include <iostream>
#include <assert.h>

using namespace std;


typedef struct Tokenized {
  string m_command;
  string m_package;
  vector<string> m_dependencies;
} Tokenized_t;


class Tokenizer
{
  string m_unparsed;
  Tokenized_t m_tokenized;

private:

  static void split(string input, char delim, vector<string> *items) {
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
   * <dependencies> is a comma delimeted vector.
   * The tokenize method will perform the following:
   * 1) verify input is valid
   * 2) split items by '|' delimeter - will always produce three strings, when valid
   * 3) ensure mandatory fields are present
   * 4) split, if optional dependencies are present, dependencies into a vector, using comma as a delimeter.
   *
   * tokenized result is return
   * nullptr returned on parsing error
   */
  void tokenize() {
    vector<string> items;
    split(m_unparsed, '|', &items);

    if (items.size() != 3) {
      cout << "Expected three tokens, got " << items.size() << endl;
      return;
    }

    m_tokenized.m_command = items[0];
    m_tokenized.m_package = items[1];

    string depends(items[2]);
    // a newline character is expected as the last character
    if (depends.back() != '\n') {
      m_tokenized.m_command = ""; // clear out the results and return;
      m_tokenized.m_package = ""; // clear out the results and return;
      cout << "Expected newline is missing at end of string: " << depends << endl;
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
  
  
