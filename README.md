# packageserver

## Design Overview

This program presents a package indexer server.  The server follows the specifications provided in the
challenge instructions.

In order to manage  and represent package dependencies, a directed acyclic graph (DAG) is used.  In the case of this implementation, each vertex in the DAG is potentially doubly linked: containing a list of dependendencies and depedent verticies.  The list of dependent verticies is important to quickly determine if removing a package (vertex) should fail, because other packages depend on it.  What a DAG also allows for is the detection of circular dependencies.  I did notice that the DO testing tool does not attempt to create a circular dependency.  Even so, it is an important aspect of a production package indexer would be to avoid circular dependencies.

The potential for circular dependicies comes the "INDEX update" operation.  The INDEX operation has two modes: 1) INDEX a new package 2) INDEX a package that exists and update its dependencies with the list provided.  This second mode of indexing presents the potential for creating a circular dependency.  Consider this example:

INDEX|baz|
INDEX|bar|baz
INDEX|foo|bar

The Graph is now foo->bar->baz

INDEX|baz|foo

This command will create a circular dependency. Such a situation will make it impossible to remove any of these
packages.  Thus, in this implementation, an attempted circular dependency will result in an ERROR.

A DAG is good for dependency relationships, but a poor structure for searching. (This implementation could be
optimized to perform a topographical sort as a way to improve searching.)  For this purpose, verticies are stored in a hashtable.  The standard C++ unordered_map serves as a hashtable with constant lookup and insertion time.  Packages are stored in the table by name.  Given that keys are unique, this prevents the insertion of duplicate records.

The data structures described are defined as part of the PackageTable class.  A PackageTable object provides the interfaces for performing a package lookup (QUERY), removal (REMOVE) and insertion (INDEX.)

In the client-server model defined, commands are new-line orriented and delimited using '|'.  The Tokenizer class is defined to encapsulate all error checking for the input command:  is it formatted correctly, does the command meet the specification etc ... A tokenized result is used to differentiate the two mandatory inputs (command|package) and the optional dependencies list.

To meet the concurrecy requirements for the challenge, a multithreaded, producer-consumer model is used.  A producer thread (main) accepts new client connections and places the resultant socket descriptors into a queue (RequestQueue.)  A pool of consumer threads waits on a new socket descriptor being added to the queue.  With the use of a conditional variable, threads waiting to dequeue are signiled when a socket descriptor is enqueued.

When a consumer thread pops a socket descriptor off the queue, it will read the socket to receieve the client command.  The command is passed to the Tokenizer.  If the command is valid, an associated PackageTable interface is used. The result of executing the command (or an error due to failed tokenizing and parsing) is written back to the client.  The consumer thread then will attempt to read the socket again.  If the client is done sending commands, it will close the socket.  This will cause the consumer thread attempt to dequeue a new socket descriptor from the RequestQueue.

The RequestQueue enables thread synchronization for ensuring one consumer handles new client connection.  In order to support 100 concurrent client connections, 100 consumer threads are used.  (An input integer value to ``packageserver`` will override the default number of consumer threads.)

Synchronization of thread access to the PackageTable is handled with a mutex lock.

## Building packageserver

Makefiles are generated using cmake.  This program is written using C++11 and requires g++-4.9 or later.

Unit tests are written using GTest and will require the gtest library to be installed.

`make` will build the packageserver binary and all tests
`make test` will run all tests

Running tests...
Test project /home/ubuntu/proj/packageindex
    Start 1: runPackageTests
1/5 Test #1: runPackageTests ..................   Passed    0.00 sec
    Start 2: runPackageTableTests
2/5 Test #2: runPackageTableTests .............   Passed    0.00 sec
    Start 3: runTokenizerTests
3/5 Test #3: runTokenizerTests ................   Passed    0.00 sec
    Start 4: runRequestTests
4/5 Test #4: runRequestTests ..................   Passed    0.00 sec
    Start 5: runRequestQueueTests
5/5 Test #5: runRequestQueueTests .............   Passed    0.00 sec

100% tests passed, 0 tests failed out of 5

Total Test time (real) =   0.01 sec

## Running packageserver

The program, ``packageserver``, runs with no parameters.  For tuning and debugging purposes, a single integer
input can be used to change the number of consumer threads created.  For example, this command will override the default 100 consumer threads and create only 10.

./packageserver 10

## Testing packageserver

Unit tests were written for testing the Package, PackageTable, RequestQueue and Tokenizer datastructures.

A simple client (packageclient) was written for simple, single threaded, end-to-end integration testing.

The do-package-tree binary (and test-suite source) was used for performing final end-to-end multithreaded testing.  The do-package-tree was run with varying levels of concurrecy (up to 100), seed value and unluckiness values.  All tests pass.

Valgrind was used to test for memory leaks in the packageserver and test programs.

