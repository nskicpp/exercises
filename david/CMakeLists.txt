project(nskicpp-david)
cmake_minimum_required(VERSION 3.1)

# Target C++14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
  # General warning flags
  add_compile_options(-Werror -Wall -Wextra -pedantic)
  # Turn on optimization
  add_compile_options(-O3 -fvectorize)
endif()

if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
  # General warning flags
  add_compile_options(-Werror -Wall -Wextra -pedantic -pedantic-errors)
  # Turn on additional warnings
  add_compile_options(-Wcast-align -Wcast-qual -Wconversion -Wformat
                      -Wlogical-op -Wno-deprecated-declarations
                      -Wreturn-local-addr -Wshadow -Wsign-conversion
                      -Wswitch-enum -Wundef -Wuninitialized -Wuseless-cast
                      -Wzero-as-null-pointer-constant)
  # Turn on optimization
  add_compile_options(-O3 -flto -fsized-deallocation)
endif()

add_executable(prompt_name prompt_name.cpp)

enable_testing()
add_test(NAME test_prompt_name0 COMMAND "/bin/sh" "-c" "echo David | ./prompt_name")
set_tests_properties(test_prompt_name0
  PROPERTIES PASS_REGULAR_EXPRESSION "Hello, David")
add_test(NAME test_prompt_name1 COMMAND "/bin/sh" "-c" "echo Michael Mauer | ./prompt_name")
set_tests_properties(test_prompt_name1
  PROPERTIES PASS_REGULAR_EXPRESSION "Hello, Michael Mauer")
