#include "Package.h"

using namespace std;

class PackageTable
{

  unordered_map<string, Package *> m_table;

 public:
  PackageTable() {}
  ~PackageTable() {
    m_table.clear();
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
    Package *myPackage = new Package(inPackage);
    if (lookup(inPackage) != nullptr) {
      // XXX package is already installed ... what is the behavior?
      // XXX treat as noop
      cout << "Duplicate insert attempt for package " << inPackage << endl;
      return 0;
    }
    for (string dep : inDeps) {
      // assert(dep != inPackage);

      if ((Package *depPackage = lookup(dep)) == nullptr) {
	// missing dependency, return error
	cout << "Missing dependency " << dep << " for package " << inPackage << endl;
	return -1;
      } else {
	// XXX check for dup deps?
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
      




    


