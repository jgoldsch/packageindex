#include <string>
#include <list>
#include <iostream>

using namespace std;

class Package
{
  string m_name;
  list<Package *> m_dependents;
  list<Package *> m_dependencies;

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

  /**
   * Creates a Graph Edge between this and dependent package inP
   * Resultant Graph will be this->inP,
   * where: this depends on inP AND inP is a dependent of this
   *
   * return 0 on success
   * returns -1 on failure 
   */
  int addDependency(Package *inP) {
    int err;

    // Disallow circular dependencies by depending on the same package as 'this'
    if (inP->getName() == getName()) {
      return -1;
    }

    if ((err = inP->addDependent(this)) == -1) {
      cout << "Dependent add to package " << inP->getName() << "failed with " << err << endl;
      return err;
    }
    m_dependencies.push_back(inP);
    
    return 0;
  }

  int removeDependency(Package *inP) {
    inP->removeDependent(this);
    m_dependencies.remove(inP);
    return 0;
  }

  int addDependent(Package *inP) {
    // XXX test for circular dependency
    m_dependents.push_back(inP);
    return 0;
  }

  int removeDependent(Package *inP) {
    m_dependents.remove(inP);
    return 0;
  }

  void printDependencies() {
    cout << "Direct dependencies for " << m_name << endl;
    for (Package *p : m_dependents) {
      cout << p->getName() << endl;
    }
  }
};

inline bool operator==(const Package& lhs, const Package& rhs){ return (lhs.getName() == rhs.getName()); }
inline bool operator!=(const Package& lhs, const Package& rhs){ return !(lhs == rhs); }
