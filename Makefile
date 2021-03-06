# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

# Default target executed when no arguments are given to make.
default_target: all
.PHONY : default_target

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

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running interactive CMake command-line interface..."
	/usr/bin/cmake -i .
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache
.PHONY : edit_cache/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache
.PHONY : rebuild_cache/fast

# Special rule for the target test
test:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running tests..."
	/usr/bin/ctest --force-new-ctest-process $(ARGS)
.PHONY : test

# Special rule for the target test
test/fast: test
.PHONY : test/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/ubuntu/proj/packageindex/CMakeFiles /home/ubuntu/proj/packageindex/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/ubuntu/proj/packageindex/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean
.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named Continuous

# Build rule for target.
Continuous: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 Continuous
.PHONY : Continuous

# fast build rule for target.
Continuous/fast:
	$(MAKE) -f CMakeFiles/Continuous.dir/build.make CMakeFiles/Continuous.dir/build
.PHONY : Continuous/fast

#=============================================================================
# Target rules for targets named ContinuousBuild

# Build rule for target.
ContinuousBuild: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 ContinuousBuild
.PHONY : ContinuousBuild

# fast build rule for target.
ContinuousBuild/fast:
	$(MAKE) -f CMakeFiles/ContinuousBuild.dir/build.make CMakeFiles/ContinuousBuild.dir/build
.PHONY : ContinuousBuild/fast

#=============================================================================
# Target rules for targets named ContinuousConfigure

# Build rule for target.
ContinuousConfigure: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 ContinuousConfigure
.PHONY : ContinuousConfigure

# fast build rule for target.
ContinuousConfigure/fast:
	$(MAKE) -f CMakeFiles/ContinuousConfigure.dir/build.make CMakeFiles/ContinuousConfigure.dir/build
.PHONY : ContinuousConfigure/fast

#=============================================================================
# Target rules for targets named ContinuousCoverage

# Build rule for target.
ContinuousCoverage: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 ContinuousCoverage
.PHONY : ContinuousCoverage

# fast build rule for target.
ContinuousCoverage/fast:
	$(MAKE) -f CMakeFiles/ContinuousCoverage.dir/build.make CMakeFiles/ContinuousCoverage.dir/build
.PHONY : ContinuousCoverage/fast

#=============================================================================
# Target rules for targets named ContinuousMemCheck

# Build rule for target.
ContinuousMemCheck: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 ContinuousMemCheck
.PHONY : ContinuousMemCheck

# fast build rule for target.
ContinuousMemCheck/fast:
	$(MAKE) -f CMakeFiles/ContinuousMemCheck.dir/build.make CMakeFiles/ContinuousMemCheck.dir/build
.PHONY : ContinuousMemCheck/fast

#=============================================================================
# Target rules for targets named ContinuousStart

# Build rule for target.
ContinuousStart: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 ContinuousStart
.PHONY : ContinuousStart

# fast build rule for target.
ContinuousStart/fast:
	$(MAKE) -f CMakeFiles/ContinuousStart.dir/build.make CMakeFiles/ContinuousStart.dir/build
.PHONY : ContinuousStart/fast

#=============================================================================
# Target rules for targets named ContinuousSubmit

# Build rule for target.
ContinuousSubmit: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 ContinuousSubmit
.PHONY : ContinuousSubmit

# fast build rule for target.
ContinuousSubmit/fast:
	$(MAKE) -f CMakeFiles/ContinuousSubmit.dir/build.make CMakeFiles/ContinuousSubmit.dir/build
.PHONY : ContinuousSubmit/fast

#=============================================================================
# Target rules for targets named ContinuousTest

# Build rule for target.
ContinuousTest: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 ContinuousTest
.PHONY : ContinuousTest

# fast build rule for target.
ContinuousTest/fast:
	$(MAKE) -f CMakeFiles/ContinuousTest.dir/build.make CMakeFiles/ContinuousTest.dir/build
.PHONY : ContinuousTest/fast

#=============================================================================
# Target rules for targets named ContinuousUpdate

# Build rule for target.
ContinuousUpdate: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 ContinuousUpdate
.PHONY : ContinuousUpdate

# fast build rule for target.
ContinuousUpdate/fast:
	$(MAKE) -f CMakeFiles/ContinuousUpdate.dir/build.make CMakeFiles/ContinuousUpdate.dir/build
.PHONY : ContinuousUpdate/fast

#=============================================================================
# Target rules for targets named Experimental

# Build rule for target.
Experimental: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 Experimental
.PHONY : Experimental

# fast build rule for target.
Experimental/fast:
	$(MAKE) -f CMakeFiles/Experimental.dir/build.make CMakeFiles/Experimental.dir/build
.PHONY : Experimental/fast

#=============================================================================
# Target rules for targets named ExperimentalBuild

# Build rule for target.
ExperimentalBuild: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 ExperimentalBuild
.PHONY : ExperimentalBuild

# fast build rule for target.
ExperimentalBuild/fast:
	$(MAKE) -f CMakeFiles/ExperimentalBuild.dir/build.make CMakeFiles/ExperimentalBuild.dir/build
.PHONY : ExperimentalBuild/fast

#=============================================================================
# Target rules for targets named ExperimentalConfigure

# Build rule for target.
ExperimentalConfigure: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 ExperimentalConfigure
.PHONY : ExperimentalConfigure

# fast build rule for target.
ExperimentalConfigure/fast:
	$(MAKE) -f CMakeFiles/ExperimentalConfigure.dir/build.make CMakeFiles/ExperimentalConfigure.dir/build
.PHONY : ExperimentalConfigure/fast

#=============================================================================
# Target rules for targets named ExperimentalCoverage

# Build rule for target.
ExperimentalCoverage: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 ExperimentalCoverage
.PHONY : ExperimentalCoverage

# fast build rule for target.
ExperimentalCoverage/fast:
	$(MAKE) -f CMakeFiles/ExperimentalCoverage.dir/build.make CMakeFiles/ExperimentalCoverage.dir/build
.PHONY : ExperimentalCoverage/fast

#=============================================================================
# Target rules for targets named ExperimentalMemCheck

# Build rule for target.
ExperimentalMemCheck: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 ExperimentalMemCheck
.PHONY : ExperimentalMemCheck

# fast build rule for target.
ExperimentalMemCheck/fast:
	$(MAKE) -f CMakeFiles/ExperimentalMemCheck.dir/build.make CMakeFiles/ExperimentalMemCheck.dir/build
.PHONY : ExperimentalMemCheck/fast

#=============================================================================
# Target rules for targets named ExperimentalStart

# Build rule for target.
ExperimentalStart: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 ExperimentalStart
.PHONY : ExperimentalStart

# fast build rule for target.
ExperimentalStart/fast:
	$(MAKE) -f CMakeFiles/ExperimentalStart.dir/build.make CMakeFiles/ExperimentalStart.dir/build
.PHONY : ExperimentalStart/fast

#=============================================================================
# Target rules for targets named ExperimentalSubmit

# Build rule for target.
ExperimentalSubmit: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 ExperimentalSubmit
.PHONY : ExperimentalSubmit

# fast build rule for target.
ExperimentalSubmit/fast:
	$(MAKE) -f CMakeFiles/ExperimentalSubmit.dir/build.make CMakeFiles/ExperimentalSubmit.dir/build
.PHONY : ExperimentalSubmit/fast

#=============================================================================
# Target rules for targets named ExperimentalTest

# Build rule for target.
ExperimentalTest: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 ExperimentalTest
.PHONY : ExperimentalTest

# fast build rule for target.
ExperimentalTest/fast:
	$(MAKE) -f CMakeFiles/ExperimentalTest.dir/build.make CMakeFiles/ExperimentalTest.dir/build
.PHONY : ExperimentalTest/fast

#=============================================================================
# Target rules for targets named ExperimentalUpdate

# Build rule for target.
ExperimentalUpdate: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 ExperimentalUpdate
.PHONY : ExperimentalUpdate

# fast build rule for target.
ExperimentalUpdate/fast:
	$(MAKE) -f CMakeFiles/ExperimentalUpdate.dir/build.make CMakeFiles/ExperimentalUpdate.dir/build
.PHONY : ExperimentalUpdate/fast

#=============================================================================
# Target rules for targets named Nightly

# Build rule for target.
Nightly: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 Nightly
.PHONY : Nightly

# fast build rule for target.
Nightly/fast:
	$(MAKE) -f CMakeFiles/Nightly.dir/build.make CMakeFiles/Nightly.dir/build
.PHONY : Nightly/fast

#=============================================================================
# Target rules for targets named NightlyBuild

# Build rule for target.
NightlyBuild: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 NightlyBuild
.PHONY : NightlyBuild

# fast build rule for target.
NightlyBuild/fast:
	$(MAKE) -f CMakeFiles/NightlyBuild.dir/build.make CMakeFiles/NightlyBuild.dir/build
.PHONY : NightlyBuild/fast

#=============================================================================
# Target rules for targets named NightlyConfigure

# Build rule for target.
NightlyConfigure: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 NightlyConfigure
.PHONY : NightlyConfigure

# fast build rule for target.
NightlyConfigure/fast:
	$(MAKE) -f CMakeFiles/NightlyConfigure.dir/build.make CMakeFiles/NightlyConfigure.dir/build
.PHONY : NightlyConfigure/fast

#=============================================================================
# Target rules for targets named NightlyCoverage

# Build rule for target.
NightlyCoverage: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 NightlyCoverage
.PHONY : NightlyCoverage

# fast build rule for target.
NightlyCoverage/fast:
	$(MAKE) -f CMakeFiles/NightlyCoverage.dir/build.make CMakeFiles/NightlyCoverage.dir/build
.PHONY : NightlyCoverage/fast

#=============================================================================
# Target rules for targets named NightlyMemCheck

# Build rule for target.
NightlyMemCheck: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 NightlyMemCheck
.PHONY : NightlyMemCheck

# fast build rule for target.
NightlyMemCheck/fast:
	$(MAKE) -f CMakeFiles/NightlyMemCheck.dir/build.make CMakeFiles/NightlyMemCheck.dir/build
.PHONY : NightlyMemCheck/fast

#=============================================================================
# Target rules for targets named NightlyMemoryCheck

# Build rule for target.
NightlyMemoryCheck: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 NightlyMemoryCheck
.PHONY : NightlyMemoryCheck

# fast build rule for target.
NightlyMemoryCheck/fast:
	$(MAKE) -f CMakeFiles/NightlyMemoryCheck.dir/build.make CMakeFiles/NightlyMemoryCheck.dir/build
.PHONY : NightlyMemoryCheck/fast

#=============================================================================
# Target rules for targets named NightlyStart

# Build rule for target.
NightlyStart: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 NightlyStart
.PHONY : NightlyStart

# fast build rule for target.
NightlyStart/fast:
	$(MAKE) -f CMakeFiles/NightlyStart.dir/build.make CMakeFiles/NightlyStart.dir/build
.PHONY : NightlyStart/fast

#=============================================================================
# Target rules for targets named NightlySubmit

# Build rule for target.
NightlySubmit: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 NightlySubmit
.PHONY : NightlySubmit

# fast build rule for target.
NightlySubmit/fast:
	$(MAKE) -f CMakeFiles/NightlySubmit.dir/build.make CMakeFiles/NightlySubmit.dir/build
.PHONY : NightlySubmit/fast

#=============================================================================
# Target rules for targets named NightlyTest

# Build rule for target.
NightlyTest: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 NightlyTest
.PHONY : NightlyTest

# fast build rule for target.
NightlyTest/fast:
	$(MAKE) -f CMakeFiles/NightlyTest.dir/build.make CMakeFiles/NightlyTest.dir/build
.PHONY : NightlyTest/fast

#=============================================================================
# Target rules for targets named NightlyUpdate

# Build rule for target.
NightlyUpdate: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 NightlyUpdate
.PHONY : NightlyUpdate

# fast build rule for target.
NightlyUpdate/fast:
	$(MAKE) -f CMakeFiles/NightlyUpdate.dir/build.make CMakeFiles/NightlyUpdate.dir/build
.PHONY : NightlyUpdate/fast

#=============================================================================
# Target rules for targets named packageclient

# Build rule for target.
packageclient: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 packageclient
.PHONY : packageclient

# fast build rule for target.
packageclient/fast:
	$(MAKE) -f CMakeFiles/packageclient.dir/build.make CMakeFiles/packageclient.dir/build
.PHONY : packageclient/fast

#=============================================================================
# Target rules for targets named packageserver

# Build rule for target.
packageserver: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 packageserver
.PHONY : packageserver

# fast build rule for target.
packageserver/fast:
	$(MAKE) -f CMakeFiles/packageserver.dir/build.make CMakeFiles/packageserver.dir/build
.PHONY : packageserver/fast

#=============================================================================
# Target rules for targets named runPackageTableTests

# Build rule for target.
runPackageTableTests: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 runPackageTableTests
.PHONY : runPackageTableTests

# fast build rule for target.
runPackageTableTests/fast:
	$(MAKE) -f CMakeFiles/runPackageTableTests.dir/build.make CMakeFiles/runPackageTableTests.dir/build
.PHONY : runPackageTableTests/fast

#=============================================================================
# Target rules for targets named runPackageTests

# Build rule for target.
runPackageTests: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 runPackageTests
.PHONY : runPackageTests

# fast build rule for target.
runPackageTests/fast:
	$(MAKE) -f CMakeFiles/runPackageTests.dir/build.make CMakeFiles/runPackageTests.dir/build
.PHONY : runPackageTests/fast

#=============================================================================
# Target rules for targets named runRequestQueueTests

# Build rule for target.
runRequestQueueTests: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 runRequestQueueTests
.PHONY : runRequestQueueTests

# fast build rule for target.
runRequestQueueTests/fast:
	$(MAKE) -f CMakeFiles/runRequestQueueTests.dir/build.make CMakeFiles/runRequestQueueTests.dir/build
.PHONY : runRequestQueueTests/fast

#=============================================================================
# Target rules for targets named runRequestTests

# Build rule for target.
runRequestTests: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 runRequestTests
.PHONY : runRequestTests

# fast build rule for target.
runRequestTests/fast:
	$(MAKE) -f CMakeFiles/runRequestTests.dir/build.make CMakeFiles/runRequestTests.dir/build
.PHONY : runRequestTests/fast

#=============================================================================
# Target rules for targets named runTokenizerTests

# Build rule for target.
runTokenizerTests: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 runTokenizerTests
.PHONY : runTokenizerTests

# fast build rule for target.
runTokenizerTests/fast:
	$(MAKE) -f CMakeFiles/runTokenizerTests.dir/build.make CMakeFiles/runTokenizerTests.dir/build
.PHONY : runTokenizerTests/fast

PackageTable_test.o: PackageTable_test.cpp.o
.PHONY : PackageTable_test.o

# target to build an object file
PackageTable_test.cpp.o:
	$(MAKE) -f CMakeFiles/runPackageTableTests.dir/build.make CMakeFiles/runPackageTableTests.dir/PackageTable_test.cpp.o
.PHONY : PackageTable_test.cpp.o

PackageTable_test.i: PackageTable_test.cpp.i
.PHONY : PackageTable_test.i

# target to preprocess a source file
PackageTable_test.cpp.i:
	$(MAKE) -f CMakeFiles/runPackageTableTests.dir/build.make CMakeFiles/runPackageTableTests.dir/PackageTable_test.cpp.i
.PHONY : PackageTable_test.cpp.i

PackageTable_test.s: PackageTable_test.cpp.s
.PHONY : PackageTable_test.s

# target to generate assembly for a file
PackageTable_test.cpp.s:
	$(MAKE) -f CMakeFiles/runPackageTableTests.dir/build.make CMakeFiles/runPackageTableTests.dir/PackageTable_test.cpp.s
.PHONY : PackageTable_test.cpp.s

Package_test.o: Package_test.cpp.o
.PHONY : Package_test.o

# target to build an object file
Package_test.cpp.o:
	$(MAKE) -f CMakeFiles/runPackageTests.dir/build.make CMakeFiles/runPackageTests.dir/Package_test.cpp.o
.PHONY : Package_test.cpp.o

Package_test.i: Package_test.cpp.i
.PHONY : Package_test.i

# target to preprocess a source file
Package_test.cpp.i:
	$(MAKE) -f CMakeFiles/runPackageTests.dir/build.make CMakeFiles/runPackageTests.dir/Package_test.cpp.i
.PHONY : Package_test.cpp.i

Package_test.s: Package_test.cpp.s
.PHONY : Package_test.s

# target to generate assembly for a file
Package_test.cpp.s:
	$(MAKE) -f CMakeFiles/runPackageTests.dir/build.make CMakeFiles/runPackageTests.dir/Package_test.cpp.s
.PHONY : Package_test.cpp.s

RequestQueue_test.o: RequestQueue_test.cpp.o
.PHONY : RequestQueue_test.o

# target to build an object file
RequestQueue_test.cpp.o:
	$(MAKE) -f CMakeFiles/runRequestQueueTests.dir/build.make CMakeFiles/runRequestQueueTests.dir/RequestQueue_test.cpp.o
.PHONY : RequestQueue_test.cpp.o

RequestQueue_test.i: RequestQueue_test.cpp.i
.PHONY : RequestQueue_test.i

# target to preprocess a source file
RequestQueue_test.cpp.i:
	$(MAKE) -f CMakeFiles/runRequestQueueTests.dir/build.make CMakeFiles/runRequestQueueTests.dir/RequestQueue_test.cpp.i
.PHONY : RequestQueue_test.cpp.i

RequestQueue_test.s: RequestQueue_test.cpp.s
.PHONY : RequestQueue_test.s

# target to generate assembly for a file
RequestQueue_test.cpp.s:
	$(MAKE) -f CMakeFiles/runRequestQueueTests.dir/build.make CMakeFiles/runRequestQueueTests.dir/RequestQueue_test.cpp.s
.PHONY : RequestQueue_test.cpp.s

Request_test.o: Request_test.cpp.o
.PHONY : Request_test.o

# target to build an object file
Request_test.cpp.o:
	$(MAKE) -f CMakeFiles/runRequestTests.dir/build.make CMakeFiles/runRequestTests.dir/Request_test.cpp.o
.PHONY : Request_test.cpp.o

Request_test.i: Request_test.cpp.i
.PHONY : Request_test.i

# target to preprocess a source file
Request_test.cpp.i:
	$(MAKE) -f CMakeFiles/runRequestTests.dir/build.make CMakeFiles/runRequestTests.dir/Request_test.cpp.i
.PHONY : Request_test.cpp.i

Request_test.s: Request_test.cpp.s
.PHONY : Request_test.s

# target to generate assembly for a file
Request_test.cpp.s:
	$(MAKE) -f CMakeFiles/runRequestTests.dir/build.make CMakeFiles/runRequestTests.dir/Request_test.cpp.s
.PHONY : Request_test.cpp.s

Tokenizer_test.o: Tokenizer_test.cpp.o
.PHONY : Tokenizer_test.o

# target to build an object file
Tokenizer_test.cpp.o:
	$(MAKE) -f CMakeFiles/runTokenizerTests.dir/build.make CMakeFiles/runTokenizerTests.dir/Tokenizer_test.cpp.o
.PHONY : Tokenizer_test.cpp.o

Tokenizer_test.i: Tokenizer_test.cpp.i
.PHONY : Tokenizer_test.i

# target to preprocess a source file
Tokenizer_test.cpp.i:
	$(MAKE) -f CMakeFiles/runTokenizerTests.dir/build.make CMakeFiles/runTokenizerTests.dir/Tokenizer_test.cpp.i
.PHONY : Tokenizer_test.cpp.i

Tokenizer_test.s: Tokenizer_test.cpp.s
.PHONY : Tokenizer_test.s

# target to generate assembly for a file
Tokenizer_test.cpp.s:
	$(MAKE) -f CMakeFiles/runTokenizerTests.dir/build.make CMakeFiles/runTokenizerTests.dir/Tokenizer_test.cpp.s
.PHONY : Tokenizer_test.cpp.s

client.o: client.cpp.o
.PHONY : client.o

# target to build an object file
client.cpp.o:
	$(MAKE) -f CMakeFiles/packageclient.dir/build.make CMakeFiles/packageclient.dir/client.cpp.o
.PHONY : client.cpp.o

client.i: client.cpp.i
.PHONY : client.i

# target to preprocess a source file
client.cpp.i:
	$(MAKE) -f CMakeFiles/packageclient.dir/build.make CMakeFiles/packageclient.dir/client.cpp.i
.PHONY : client.cpp.i

client.s: client.cpp.s
.PHONY : client.s

# target to generate assembly for a file
client.cpp.s:
	$(MAKE) -f CMakeFiles/packageclient.dir/build.make CMakeFiles/packageclient.dir/client.cpp.s
.PHONY : client.cpp.s

server.o: server.cpp.o
.PHONY : server.o

# target to build an object file
server.cpp.o:
	$(MAKE) -f CMakeFiles/packageserver.dir/build.make CMakeFiles/packageserver.dir/server.cpp.o
.PHONY : server.cpp.o

server.i: server.cpp.i
.PHONY : server.i

# target to preprocess a source file
server.cpp.i:
	$(MAKE) -f CMakeFiles/packageserver.dir/build.make CMakeFiles/packageserver.dir/server.cpp.i
.PHONY : server.cpp.i

server.s: server.cpp.s
.PHONY : server.s

# target to generate assembly for a file
server.cpp.s:
	$(MAKE) -f CMakeFiles/packageserver.dir/build.make CMakeFiles/packageserver.dir/server.cpp.s
.PHONY : server.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... Continuous"
	@echo "... ContinuousBuild"
	@echo "... ContinuousConfigure"
	@echo "... ContinuousCoverage"
	@echo "... ContinuousMemCheck"
	@echo "... ContinuousStart"
	@echo "... ContinuousSubmit"
	@echo "... ContinuousTest"
	@echo "... ContinuousUpdate"
	@echo "... Experimental"
	@echo "... ExperimentalBuild"
	@echo "... ExperimentalConfigure"
	@echo "... ExperimentalCoverage"
	@echo "... ExperimentalMemCheck"
	@echo "... ExperimentalStart"
	@echo "... ExperimentalSubmit"
	@echo "... ExperimentalTest"
	@echo "... ExperimentalUpdate"
	@echo "... Nightly"
	@echo "... NightlyBuild"
	@echo "... NightlyConfigure"
	@echo "... NightlyCoverage"
	@echo "... NightlyMemCheck"
	@echo "... NightlyMemoryCheck"
	@echo "... NightlyStart"
	@echo "... NightlySubmit"
	@echo "... NightlyTest"
	@echo "... NightlyUpdate"
	@echo "... edit_cache"
	@echo "... packageclient"
	@echo "... packageserver"
	@echo "... rebuild_cache"
	@echo "... runPackageTableTests"
	@echo "... runPackageTests"
	@echo "... runRequestQueueTests"
	@echo "... runRequestTests"
	@echo "... runTokenizerTests"
	@echo "... test"
	@echo "... PackageTable_test.o"
	@echo "... PackageTable_test.i"
	@echo "... PackageTable_test.s"
	@echo "... Package_test.o"
	@echo "... Package_test.i"
	@echo "... Package_test.s"
	@echo "... RequestQueue_test.o"
	@echo "... RequestQueue_test.i"
	@echo "... RequestQueue_test.s"
	@echo "... Request_test.o"
	@echo "... Request_test.i"
	@echo "... Request_test.s"
	@echo "... Tokenizer_test.o"
	@echo "... Tokenizer_test.i"
	@echo "... Tokenizer_test.s"
	@echo "... client.o"
	@echo "... client.i"
	@echo "... client.s"
	@echo "... server.o"
	@echo "... server.i"
	@echo "... server.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

