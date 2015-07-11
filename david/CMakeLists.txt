project(nskicpp-david)
cmake_minimum_required(VERSION 3.1)

# Target C++14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(prompt_name prompt_name.cpp)
add_executable(poor_mans_cat poor_mans_cat.cpp)

enable_testing()
add_test(NAME test_prompt_name0 COMMAND /bin/sh -c "echo David | ./prompt_name")
set_tests_properties(test_prompt_name0
  PROPERTIES PASS_REGULAR_EXPRESSION "Hello, David")
add_test(NAME test_prompt_name1 COMMAND /bin/sh -c "echo Michael Mauer | ./prompt_name")
set_tests_properties(test_prompt_name1
  PROPERTIES PASS_REGULAR_EXPRESSION "Hello, Michael Mauer")

add_test(NAME test_poor_mans_cat0 COMMAND /bin/sh -c "echo A and B and C | ./poor_mans_cat")
set_tests_properties(test_poor_mans_cat0
  PROPERTIES PASS_REGULAR_EXPRESSION "A and B and C")
add_test(NAME test_poor_mans_cat1 COMMAND /bin/sh -c "echo 'Test \n Test 2' | ./poor_mans_cat")
set_tests_properties(test_poor_mans_cat1
  PROPERTIES PASS_REGULAR_EXPRESSION "Test \n Test 2")
