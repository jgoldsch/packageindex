cmake_minimum_required(VERSION 2.6)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
include(CTest) 
# Locate GTest
find_package(GTest REQUIRED)
enable_testing()
include_directories(${GTEST_INCLUDE_DIRS})
 
# Link runTests with what we want to test and the GTest and pthread library
add_executable(runPackageTests Package_test.cpp)
target_link_libraries(runPackageTests ${GTEST_LIBRARIES} pthread)
add_executable(runPackageTableTests PackageTable_test.cpp)
target_link_libraries(runPackageTableTests ${GTEST_LIBRARIES} pthread)

add_test( runPackageTests runPackageTests )
add_test( runPackageTableTests runPackageTableTests )
