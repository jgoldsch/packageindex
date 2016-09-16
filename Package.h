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

  void removeAllDependencies() {
    while (!m_dependencies.empty()) {
      Package *p = m_dependencies.front();
      m_dependencies.pop_front();
      (void)p->removeDependent(this);
    }
  }

  /**
   * Search dependencies (direct and otherwise) for a package name.
   * return a pointer to a found package matching the input name
   * return nullptr if no package is found in the graph
   */
  Package * search(string inName) {
    Package *target = nullptr;

    if (inName == getName()) {
      return this;
    } else {
      for (auto p : m_dependencies) {
	if ((target = p->search(inName)) != nullptr) {
	  return target;
	}
      }
    }

    return nullptr;
  }

  void printDependencies() {
    cout << "Direct dependencies for " << m_name << endl;
    for (Package *p : m_dependencies) {
      cout << p->getName() << endl;
    }
  }
};

inline bool operator==(const Package& lhs, const Package& rhs){ return (lhs.getName() == rhs.getName()); }
inline bool operator!=(const Package& lhs, const Package& rhs){ return !(lhs == rhs); }
