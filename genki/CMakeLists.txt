project(nskicpp-examples-genki)

cmake_minimum_required(VERSION 3.1)
set(CMAKE_CXX_STANDARD          14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(hello_name hello_name.cpp)

enable_testing()
add_test(NAME test_hello_name COMMAND hello_name)
set_tests_properties(test_hello_name
  PROPERTIES PASS_REGULAR_EXPRESSION "Hi .*!")
