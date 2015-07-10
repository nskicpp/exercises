project(pniedzielski-examples-response)


# Use C++14.  CMake 3.1 is required for these variables.
cmake_minimum_required(VERSION 3.1)
set(CMAKE_CXX_STANDARD          14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


# Set up the compiler options.
if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
  # General warning flags
  add_compile_options(-Werror -Wall -Wextra -pedantic)
  # Turn on optimization
  add_compile_options(-O3 -fvectorize -fsized-deallocation)
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


# Allow us to test.
enable_testing()


# GREETING
add_executable(greeting greeting.cpp)
add_test(NAME test_greeting1 COMMAND bash -c "echo Patrick | ./greeting")
set_tests_properties(test_greeting1
  PROPERTIES PASS_REGULAR_EXPRESSION "Patrick")
add_test(NAME test_greeting2 COMMAND bash -c "echo Patrick M | ./greeting")
set_tests_properties(test_greeting2
  PROPERTIES PASS_REGULAR_EXPRESSION "Patrick M")


# CAT
add_executable(cat cat.cpp)
foreach(num 1 2 3 4)
  set(__test_file "../t/input_lesson4.${num}.in")
  add_test(NAME "test_cat${num}"
    COMMAND bash -c "diff <(cat ${__test_file}) <(cat ${__test_file} | ./cat)")
endforeach()
