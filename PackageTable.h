#include "Package.h"
#include <unordered_map>
#include <list>
#include <mutex>
#include <assert.h>

#ifndef NDEBUG
#define NDEBUG
#endif	/* NDEBUG */

using namespace std;

class PackageTable
{
  unordered_map<string, Package *> m_table;
  std::mutex m_lock;
 public:
  PackageTable() {}
  ~PackageTable() {
    m_table.clear();
  }

  void print() {
    std::lock_guard<std::mutex> lock(m_lock);
    for (auto it = m_table.begin(); it != m_table.end(); ++it) {
      Package *p = it->second;
      if (p != nullptr) {
	p->printDependencies();
      }
    }
  }

  Package *lookup(string inName) {
    return m_table[inName];
  }

  int insert_update(Package *inPackage, list<string> inDeps) {
    list<Package *> myDeps;
    assert(inPackage != nullptr);
    for (string dep : inDeps) {
      assert(dep != inPackage->getName());
      Package * depPackage = lookup(dep);
      if (depPackage == nullptr) {
	// missing dependency, return error
#ifndef NDEBUG
	cout << "Missing dependency " << dep << " for package " << inPackage->getName() << endl;
#endif	/* !NDEBUG */
	return -1;
      } else {
	// Check for circular dependency
	if (depPackage->search(inPackage->getName()) != nullptr) {
	  cout << "Circular dependency detected for package " << inPackage->getName() <<
	    " and updated dependency " << depPackage->getName() << endl;
	  return 1;
	} else {
	  myDeps.push_back(depPackage);
	}
      }
    }
    inPackage->removeAllDependencies();
    for (auto p : myDeps) {
      inPackage->addDependency(p);
    }
    return 0;
  }

  int insert_new(Package *inPackage, list<string> inDeps) {
    list<Package *> myDeps;
    assert(inPackage != nullptr);
    for (string dep : inDeps) {
      assert(dep != inPackage->getName());
      Package * depPackage = lookup(dep);
      if (depPackage == nullptr) {
	// missing dependency, return error
#ifndef NDEBUG
	cout << "Missing dependency " << dep << " for package " << inPackage->getName() << endl;
#endif	/* !NDEBUG */
	delete inPackage;
	return -1;
      } else {
	myDeps.push_back(depPackage);
      }
    }

    // All dependencies are met.
    for (Package *d : myDeps) {
      inPackage->addDependency(d);
    }

    m_table[inPackage->getName()] = inPackage;
    return 0;
  }

  /**
   * Insert a package into the table if dependencies are met
   * returns 0 on success
   * returns 1 on error, due to a circular dependency
   * returns -1 on failure, due to missing dependency
   */
  int insert(string inPackageStr, list<string> inDeps) {
    int err;
    std::lock_guard<std::mutex> lock(m_lock);
    Package *myPackage = lookup(inPackageStr);
    if (myPackage != nullptr) {
      // This is an update of an existing package and needs to be handled differently
      err = insert_update(myPackage, inDeps);
    } else {
      myPackage = new Package(inPackageStr);
      err = insert_new(myPackage, inDeps);
    }

    return err;
  }

  int remove(string inPackageStr) {
    std::lock_guard<std::mutex> lock(m_lock);
    Package *remPackage = lookup(inPackageStr);
    if (remPackage == nullptr) {
	// removing a package that doesn't exist is a noop
	return 0;
    }

    // A package that is a sink node in the graph has no dependencies, thus it can be removed
    if (remPackage->isSink()) {
      remPackage->removeAllDependencies();
      m_table.erase(inPackageStr);
      delete remPackage;
      return 0;
    } else {
      // Package that is not a sink is a dependency for another package,
      // thus we must fail the removal.
      return -1;
    }

    return 0;
  }

  int query(string inPackageStr) {
    std::lock_guard<std::mutex> lock(m_lock);
    Package *queryPackage = lookup(inPackageStr);

    if (queryPackage == nullptr) {
      // Package is not indexed
      return -1;
    } else {
      // Package is indexed
      return 0;
    }
  }

};

      




    


