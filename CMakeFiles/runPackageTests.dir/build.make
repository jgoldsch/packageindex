# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list

# Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/ubuntu/proj/packageindex

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ubuntu/proj/packageindex

# Include any dependencies generated for this target.
include CMakeFiles/runPackageTests.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/runPackageTests.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/runPackageTests.dir/flags.make

CMakeFiles/runPackageTests.dir/Package_test.cpp.o: CMakeFiles/runPackageTests.dir/flags.make
CMakeFiles/runPackageTests.dir/Package_test.cpp.o: Package_test.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/ubuntu/proj/packageindex/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/runPackageTests.dir/Package_test.cpp.o"
	/usr/bin/g++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/runPackageTests.dir/Package_test.cpp.o -c /home/ubuntu/proj/packageindex/Package_test.cpp

CMakeFiles/runPackageTests.dir/Package_test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/runPackageTests.dir/Package_test.cpp.i"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/ubuntu/proj/packageindex/Package_test.cpp > CMakeFiles/runPackageTests.dir/Package_test.cpp.i

CMakeFiles/runPackageTests.dir/Package_test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/runPackageTests.dir/Package_test.cpp.s"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/ubuntu/proj/packageindex/Package_test.cpp -o CMakeFiles/runPackageTests.dir/Package_test.cpp.s

CMakeFiles/runPackageTests.dir/Package_test.cpp.o.requires:
.PHONY : CMakeFiles/runPackageTests.dir/Package_test.cpp.o.requires

CMakeFiles/runPackageTests.dir/Package_test.cpp.o.provides: CMakeFiles/runPackageTests.dir/Package_test.cpp.o.requires
	$(MAKE) -f CMakeFiles/runPackageTests.dir/build.make CMakeFiles/runPackageTests.dir/Package_test.cpp.o.provides.build
.PHONY : CMakeFiles/runPackageTests.dir/Package_test.cpp.o.provides

CMakeFiles/runPackageTests.dir/Package_test.cpp.o.provides.build: CMakeFiles/runPackageTests.dir/Package_test.cpp.o

# Object files for target runPackageTests
runPackageTests_OBJECTS = \
"CMakeFiles/runPackageTests.dir/Package_test.cpp.o"

# External object files for target runPackageTests
runPackageTests_EXTERNAL_OBJECTS =

runPackageTests: CMakeFiles/runPackageTests.dir/Package_test.cpp.o
runPackageTests: CMakeFiles/runPackageTests.dir/build.make
runPackageTests: /usr/lib/libgtest.a
runPackageTests: CMakeFiles/runPackageTests.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable runPackageTests"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/runPackageTests.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/runPackageTests.dir/build: runPackageTests
.PHONY : CMakeFiles/runPackageTests.dir/build

CMakeFiles/runPackageTests.dir/requires: CMakeFiles/runPackageTests.dir/Package_test.cpp.o.requires
.PHONY : CMakeFiles/runPackageTests.dir/requires

CMakeFiles/runPackageTests.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/runPackageTests.dir/cmake_clean.cmake
.PHONY : CMakeFiles/runPackageTests.dir/clean

CMakeFiles/runPackageTests.dir/depend:
	cd /home/ubuntu/proj/packageindex && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ubuntu/proj/packageindex /home/ubuntu/proj/packageindex /home/ubuntu/proj/packageindex /home/ubuntu/proj/packageindex /home/ubuntu/proj/packageindex/CMakeFiles/runPackageTests.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/runPackageTests.dir/depend
