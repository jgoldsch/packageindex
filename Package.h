#include <string>
#include <list>
#include <iostream>

using namespace std;

class Package
{
  string m_name;
  list<Package> m_dependents;
  list<Package> m_dependencies;

public:
  Package(string name) : m_name(name) {}

  ~Package() {
    m_dependents.clear();
    m_dependencies.clear();
  }

  string getName() const {
    return m_name;
  }

  bool isSource() {
    return m_dependencies.empty();
  }

  bool isSink() {
    return m_dependents.empty();
  }

  void addDependency(Package inP) {
    m_dependencies.push_back(inP);
  }

  void removeDependency(Package inP) {
    m_dependencies.remove(inP);
  }

  void addDependent(Package inP) {
    m_dependents.push_back(inP);
  }

  void removeDependent(Package inP) {
    m_dependents.remove(inP);
  }

  void printDependencies() {
    cout << "Direct dependencies for " << m_name << endl;
    for (Package p : m_dependents) {
      cout << p.getName() << endl;
    }
  }
};

inline bool operator==(const Package& lhs, const Package& rhs){ return (lhs.getName() == rhs.getName()); }
inline bool operator!=(const Package& lhs, const Package& rhs){ return !(lhs == rhs); }
