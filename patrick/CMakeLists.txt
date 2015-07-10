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


# WC
add_executable(wc wc.cpp)
add_test(NAME test_wc1 COMMAND bash -c "cat ../t/input_lesson4.1.in | ./wc")
set_tests_properties(test_wc1 PROPERTIES PASS_REGULAR_EXPRESSION "9")
add_test(NAME test_wc2 COMMAND bash -c "cat ../t/input_lesson4.2.in | ./wc")
set_tests_properties(test_wc2 PROPERTIES PASS_REGULAR_EXPRESSION "14")
add_test(NAME test_wc3 COMMAND bash -c "cat ../t/input_lesson4.3.in | ./wc")
set_tests_properties(test_wc3 PROPERTIES PASS_REGULAR_EXPRESSION "11")
add_test(NAME test_wc4 COMMAND bash -c "cat ../t/input_lesson4.4.in | ./wc")
set_tests_properties(test_wc4 PROPERTIES PASS_REGULAR_EXPRESSION "12763")


# TRINARY
add_executable(trinary trinary.cpp)
add_test(NAME test_trinary1 COMMAND bash -c "echo 1 | ./trinary")
set_tests_properties(test_trinary1 PROPERTIES PASS_REGULAR_EXPRESSION "1")
add_test(NAME test_trinary2 COMMAND bash -c "echo 10 | ./trinary")
set_tests_properties(test_trinary2 PROPERTIES PASS_REGULAR_EXPRESSION "3")
add_test(NAME test_trinary3 COMMAND bash -c "echo 201 | ./trinary")
set_tests_properties(test_trinary3 PROPERTIES PASS_REGULAR_EXPRESSION "19")
add_test(NAME test_trinary4 COMMAND bash -c "echo 3 | ./trinary")
set_tests_properties(test_trinary4 PROPERTIES WILL_FAIL true)


# STACK LANGUAGE
add_executable(stack-lang stack-lang.cpp)
add_test(NAME test_stack_lang1 COMMAND
  bash -c "echo 1 print | ./stack-lang")
set_tests_properties(test_stack_lang1 PROPERTIES
  PASS_REGULAR_EXPRESSION "1")
add_test(NAME test_stack_lang2 COMMAND
  bash -c "echo 10 1 print | ./stack-lang")
set_tests_properties(test_stack_lang2 PROPERTIES
  PASS_REGULAR_EXPRESSION "10 1")
add_test(NAME test_stack_lang3 COMMAND
  bash -c "echo 10 2 + print | ./stack-lang")
set_tests_properties(test_stack_lang3 PROPERTIES
  PASS_REGULAR_EXPRESSION "12")
add_test(NAME test_stack_lang4 COMMAND
  bash -c "echo 10 2 - print | ./stack-lang")
set_tests_properties(test_stack_lang4 PROPERTIES
  PASS_REGULAR_EXPRESSION "8")
add_test(NAME test_stack_lang5 COMMAND
  bash -c "echo 10 2 '*' print | ./stack-lang")
set_tests_properties(test_stack_lang5 PROPERTIES
  PASS_REGULAR_EXPRESSION "20")
add_test(NAME test_stack_lang6 COMMAND
  bash -c "echo 10 2 / print | ./stack-lang")
set_tests_properties(test_stack_lang6 PROPERTIES
  PASS_REGULAR_EXPRESSION "5")
add_test(NAME test_stack_lang7 COMMAND
  bash -c "echo 10 2 | ./stack-lang")
set_tests_properties(test_stack_lang7 PROPERTIES
  WILL_FAIL true)
add_test(NAME test_stack_lang8 COMMAND
  bash -c "echo 10 + | ./stack-lang")
set_tests_properties(test_stack_lang8 PROPERTIES
  WILL_FAIL true)
add_test(NAME test_stack_lang9 COMMAND
  bash -c "echo 10 - | ./stack-lang")
set_tests_properties(test_stack_lang9 PROPERTIES
  WILL_FAIL true)
add_test(NAME test_stack_lang10 COMMAND
  bash -c "echo 10 * | ./stack-lang")
set_tests_properties(test_stack_lang10 PROPERTIES
  WILL_FAIL true)
add_test(NAME test_stack_lang11 COMMAND
  bash -c "echo 10 / | ./stack-lang")
set_tests_properties(test_stack_lang11 PROPERTIES
  WILL_FAIL true)
