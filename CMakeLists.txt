# Sets the minimum version of CMake for this project, which is major version 3, minor version 10, and patch version 0 in this example.
cmake_minimum_required(VERSION 3.10.0)

# Options. Turn on with 'cmake -Dmyvarname=ON'.
option(test "Build all tests." OFF) # Makes boolean 'test' available.

# The project() command that sets the project name.
project (logging_project)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-g -Wall")


#Bring the header files into the build environment.
include_directories(include)

#Can manually add the sources using the set command as follows:
#set(SOURCES src/main.cpp src/Investment.cpp)

#However, the file(GLOB...) allows for wildcard additions:
file(GLOB SOURCES "src/*.cpp")

# The add_executable() command requests that an executable is to be built using the main.cpp source file. The first argument to the add_executable() function is the name of the executable to be built, and the second argument is the source file from which to build the executable.
#add_executable(logging_main main.cpp)
add_library(project_lib ${SOURCES})
add_executable(logging_main "src/main.cpp")

target_link_libraries(logging_main project_lib)

################################
# Testing
################################
if (test)
  # This adds another subdirectory, which has 'project(gtest)'.
  add_subdirectory(googletest)
  enable_testing()

  # Include the gtest library. gtest_SOURCE_DIR is available due to
  # 'project(gtest)' above.
  include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

  ##############
  # Unit Tests
  ##############
  set(TEST_SOURCES test/BondTests.cpp test/InvestmentTests.cpp)
  add_executable(runUnitTests ${TEST_SOURCES})

  # Standard linking to gtest stuff.
  target_link_libraries(runUnitTests gtest gtest_main)

  # Extra linking for the project.
  target_link_libraries(runUnitTests project_lib)

  # This is so you can do 'make test' to see all your tests run, instead of
  # manually running the executable runUnitTests to see those specific tests.
  add_test(NAME BondTest COMMAND runUnitTests)

  # You can also omit NAME and COMMAND. The second argument could be some other
  # test executable.
  # add_test(that-other-test-I-made runUnitTests)
endif()