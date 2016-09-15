#include "Package.h"
#include <unordered_map>
#include <list>
#include <assert.h>

//#define NDEBUG

using namespace std;

class PackageTable
{

  unordered_map<string, Package *> m_table;

 public:
  PackageTable() {}
  ~PackageTable() {
    m_table.clear();
    // XXX delete Packages?
  }

  void print() {
    for (auto it = m_table.begin(); it != m_table.end(); ++it) {
      Package *p = it->second;
      p->printDependencies();
    }
  }

  Package *lookup(string inName) {
    return m_table[inName];
  }

  /**
   * Insert a package into the table if dependencies are met
   * returns 0 on success
   * returns -1 on failure, due to missing dependency
   */
  int insert(string inPackage, list<string> inDeps) {
    list<Package *> myDeps;
    Package *myPackage = lookup(inPackage);
    if (myPackage != nullptr) {
      // XXX This is an update.  Which means that a circular dependency could be found.
      // fail until this works
      return -1;
    } else {
      myPackage = new Package(inPackage);
    }
    for (string dep : inDeps) {
      assert(dep != inPackage);
      Package * depPackage = lookup(dep);
      if (depPackage == nullptr) {
	// missing dependency, return error
	cout << "Missing dependency " << dep << " for package " << inPackage << endl;
	return -1;
      } else {
	// XXX check for dup deps?
	// ASSERT no dup dependencies?
	myDeps.push_back(depPackage);
      }
    }

    // All dependencies are met.
    for (Package *d : myDeps) {
      myPackage->addDependency(d);
    }

    m_table[inPackage] = myPackage;
    return 0;
  }

  int remove(string inPackage) {
    Package *remPackage = m_table[inPackage];

    if (remPackage == nullptr) {
	// removing a package that doesn't exist is a noop
	return 0;
    }

    // A package that is a sink node in the graph has no dependencies, thus it can be removed
    if (remPackage->isSink()) {
      remPackage->removeAllDependencies();
      m_table.erase(inPackage);
      assert(m_table[inPackage] == nullptr);
      delete remPackage;
      return 0;
    } else {
      // Package is that is not a sink is an dependency for another package,
      // thus we must fail removal.
      return -1;
    }

    return 0;
  }
};

      




    


