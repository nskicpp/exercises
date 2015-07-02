project(hello_person)
cmake_minimum_required(VERSION 3.1)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(hello_person hello_person.cpp)

enable_testing()
add_test(NAME test_hello_person COMMAND hello_person)
set_tests_properties(test_hello_person
  PROPERTIES PASS_REGULAR_EXPRESSION "Hello, .*.")
