project(pniedzielski-examples-response)

# Use C++14.  CMake 3.1 is required for these variables.
cmake_minimum_required(VERSION 3.1)
set(CMAKE_CXX_STANDARD          14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(greeting greeting.cpp)

enable_testing()
add_test(NAME test_greeting_success COMMAND greeting)
set_tests_properties(test_greeting_success
  PROPERTIES PASS_REGULAR_EXPRESSION "Hello, .+!")
