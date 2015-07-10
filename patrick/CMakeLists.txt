project(pniedzielski-examples-response)

# Use C++14.  CMake 3.1 is required for these variables.
cmake_minimum_required(VERSION 3.1)
set(CMAKE_CXX_STANDARD          14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

enable_testing()

add_executable(greeting greeting.cpp)
add_test(NAME test_greeting1 COMMAND bash -c "echo Patrick | ./greeting")
set_tests_properties(test_greeting1
  PROPERTIES PASS_REGULAR_EXPRESSION "Patrick")
add_test(NAME test_greeting2 COMMAND bash -c "echo Patrick M | ./greeting")
set_tests_properties(test_greeting2
  PROPERTIES PASS_REGULAR_EXPRESSION "Patrick M")
