project(nskicpp-david)
cmake_minimum_required(VERSION 3.1)

# Target C++14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(prompt_name prompt_name.cpp)

enable_testing()
add_test(NAME test_prompt_name0 COMMAND echo "David" | prompt_name)
set_tests_properties(test_prompt_name0
  PROPERTIES PASS_REGULAR_EXPRESSION "David")
add_test(NAME test_prompt_name1 COMMAND echo "Mauer" | prompt_name)
set_tests_properties(test_prompt_name1
  PROPERTIES PASS_REGULAR_EXPRESSION "Mauer")
