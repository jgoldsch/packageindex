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
include CMakeFiles/runTokenizerTests.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/runTokenizerTests.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/runTokenizerTests.dir/flags.make

CMakeFiles/runTokenizerTests.dir/Tokenizer_test.cpp.o: CMakeFiles/runTokenizerTests.dir/flags.make
CMakeFiles/runTokenizerTests.dir/Tokenizer_test.cpp.o: Tokenizer_test.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/ubuntu/proj/packageindex/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/runTokenizerTests.dir/Tokenizer_test.cpp.o"
	/usr/bin/g++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/runTokenizerTests.dir/Tokenizer_test.cpp.o -c /home/ubuntu/proj/packageindex/Tokenizer_test.cpp

CMakeFiles/runTokenizerTests.dir/Tokenizer_test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/runTokenizerTests.dir/Tokenizer_test.cpp.i"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/ubuntu/proj/packageindex/Tokenizer_test.cpp > CMakeFiles/runTokenizerTests.dir/Tokenizer_test.cpp.i

CMakeFiles/runTokenizerTests.dir/Tokenizer_test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/runTokenizerTests.dir/Tokenizer_test.cpp.s"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/ubuntu/proj/packageindex/Tokenizer_test.cpp -o CMakeFiles/runTokenizerTests.dir/Tokenizer_test.cpp.s

CMakeFiles/runTokenizerTests.dir/Tokenizer_test.cpp.o.requires:
.PHONY : CMakeFiles/runTokenizerTests.dir/Tokenizer_test.cpp.o.requires

CMakeFiles/runTokenizerTests.dir/Tokenizer_test.cpp.o.provides: CMakeFiles/runTokenizerTests.dir/Tokenizer_test.cpp.o.requires
	$(MAKE) -f CMakeFiles/runTokenizerTests.dir/build.make CMakeFiles/runTokenizerTests.dir/Tokenizer_test.cpp.o.provides.build
.PHONY : CMakeFiles/runTokenizerTests.dir/Tokenizer_test.cpp.o.provides

CMakeFiles/runTokenizerTests.dir/Tokenizer_test.cpp.o.provides.build: CMakeFiles/runTokenizerTests.dir/Tokenizer_test.cpp.o

# Object files for target runTokenizerTests
runTokenizerTests_OBJECTS = \
"CMakeFiles/runTokenizerTests.dir/Tokenizer_test.cpp.o"

# External object files for target runTokenizerTests
runTokenizerTests_EXTERNAL_OBJECTS =

runTokenizerTests: CMakeFiles/runTokenizerTests.dir/Tokenizer_test.cpp.o
runTokenizerTests: CMakeFiles/runTokenizerTests.dir/build.make
runTokenizerTests: /usr/lib/libgtest.a
runTokenizerTests: CMakeFiles/runTokenizerTests.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable runTokenizerTests"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/runTokenizerTests.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/runTokenizerTests.dir/build: runTokenizerTests
.PHONY : CMakeFiles/runTokenizerTests.dir/build

CMakeFiles/runTokenizerTests.dir/requires: CMakeFiles/runTokenizerTests.dir/Tokenizer_test.cpp.o.requires
.PHONY : CMakeFiles/runTokenizerTests.dir/requires

CMakeFiles/runTokenizerTests.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/runTokenizerTests.dir/cmake_clean.cmake
.PHONY : CMakeFiles/runTokenizerTests.dir/clean

CMakeFiles/runTokenizerTests.dir/depend:
	cd /home/ubuntu/proj/packageindex && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ubuntu/proj/packageindex /home/ubuntu/proj/packageindex /home/ubuntu/proj/packageindex /home/ubuntu/proj/packageindex /home/ubuntu/proj/packageindex/CMakeFiles/runTokenizerTests.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/runTokenizerTests.dir/depend
