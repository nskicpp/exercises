project(nskicpp-genki)

cmake_minimum_required(VERSION 3.1)
set(CMAKE_CXX_STANDARD          14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
  # General warning flags.
  add_compile_options(-Werror -Wall -Wextra -pedantic)
  # Turn on optimization.
  add_compile_options(-O3 -fvectorize)
  # (Leaving out `fsized-deallocation` for now due to version)
endif()

if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
  # General warning flags.
  add_compile_options(-Werror -Wall -Wextra -pedantic -pedantic-errors)
  # Turn on additional warnings.
  add_compile_options(-Wcast-align -Wcast-qual -Wconversion -Wformat
                      -Wlogical-op -Wno-deprecated-declarations
                      -Wreturn-local-addr -Wshadow -Wsign-conversion
                      -Wswitch-enum -Wundef -Wuninitialized -Wuseless-cast
                      -Wzero-as-null-pointer-constant)
  # Turn on optimization.
  add_compile_options(-O3 -flto -fsized-deallocation)
endif()

enable_testing()

# LESSON 3
add_executable(hello_name hello_name.cpp)
add_test(NAME test_hello_name_1
  COMMAND /bin/bash -c "echo Genki | ./hello_name")
set_tests_properties(test_hello_name_1
  PROPERTIES PASS_REGULAR_EXPRESSION "Hi Genki!")
add_test(NAME test_hello_name_2
  COMMAND /bin/bash -c "echo Mom Mother | ./hello_name")
set_tests_properties(test_hello_name_2
  PROPERTIES PASS_REGULAR_EXPRESSION "Hi Mom!")

# LESSON 4

# Exercise 1.
add_executable(mimic mimic.cpp)
add_test(NAME test_mimic_1
  COMMAND /bin/bash -c "echo 'example input' | ./mimic")
set_tests_properties(test_mimic_1
  PROPERTIES PASS_REGULAR_EXPRESSION "example input")
add_test(NAME test_mimic_2
  COMMAND /bin/bash -c "echo 'are you a mimic?' | ./mimic")
set_tests_properties(test_mimic_2
  PROPERTIES PASS_REGULAR_EXPRESSION "are you a mimic?")

# Exercise 2.
add_executable(word_count word_count.cpp)
add_test(NAME test_word_count_1
  COMMAND /bin/bash -c "echo '' | ./word_count")
set_tests_properties(test_word_count_1
  PROPERTIES PASS_REGULAR_EXPRESSION "Word Count: 0")
add_test(NAME test_word_count_2
  COMMAND /bin/bash -c "echo 'example input' | ./word_count")
set_tests_properties(test_word_count_2
  PROPERTIES PASS_REGULAR_EXPRESSION "Word Count: 2")
add_test(NAME test_word_count_3
  COMMAND /bin/bash -c "echo 'are you a mimic?' | ./word_count")
set_tests_properties(test_word_count_3
  PROPERTIES PASS_REGULAR_EXPRESSION "Word Count: 4")

# Exercise 3.
add_executable(ternary ternary.cpp)
add_test(NAME test_ternary_1
  COMMAND /bin/bash -c "echo '0' | ./ternary")
set_tests_properties(test_ternary_1
  PROPERTIES PASS_REGULAR_EXPRESSION "0.0000")
add_test(NAME test_ternary_2
  COMMAND /bin/bash -c "echo '10' | ./ternary")
set_tests_properties(test_ternary_2
  PROPERTIES PASS_REGULAR_EXPRESSION "3.0000")
add_test(NAME test_ternary_3
  COMMAND /bin/bash -c "echo '102.11' | ./ternary")
set_tests_properties(test_ternary_3
  PROPERTIES PASS_REGULAR_EXPRESSION "11.4444")
add_test(NAME test_ternary_4
  COMMAND /bin/bash -c "echo '11111.22222' | ./ternary")
set_tests_properties(test_ternary_4
  PROPERTIES PASS_REGULAR_EXPRESSION "121.9959")
add_test(NAME test_ternary_5
  COMMAND /bin/bash -c "echo '11111.22223' | ./ternary")
set_tests_properties(test_ternary_5
  PROPERTIES PASS_REGULAR_EXPRESSION "ERROR: <3> is an invalid character.")

# Exercise 4.
add_executable(stack_lang stack_lang.cpp)
add_test(NAME test_stack_lang_1
  COMMAND /bin/bash -c "echo 'print' | ./stack_lang")
set_tests_properties(test_stack_lang_1
  PROPERTIES PASS_REGULAR_EXPRESSION "The stack is currently empty.")
add_test(NAME test_stack_lang_2
  COMMAND /bin/bash -c "echo '0 print' | ./stack_lang")
set_tests_properties(test_stack_lang_2
  PROPERTIES PASS_REGULAR_EXPRESSION "The stack is currently: 0")
add_test(NAME test_stack_lang_3
  COMMAND /bin/bash -c "echo '3 2 + print' | ./stack_lang")
set_tests_properties(test_stack_lang_3
  PROPERTIES PASS_REGULAR_EXPRESSION "The stack is currently: 5")
add_test(NAME test_stack_lang_4
  COMMAND /bin/bash -c "echo '6 2 - 2 * 4 / print' | ./stack_lang")
set_tests_properties(test_stack_lang_4
  PROPERTIES PASS_REGULAR_EXPRESSION "The stack is currently: 2")
add_test(NAME test_stack_lang_5
  COMMAND /bin/bash -c "echo '6 2 - 2 * 4 / print' | ./stack_lang")
set_tests_properties(test_stack_lang_4
  PROPERTIES PASS_REGULAR_EXPRESSION "The stack is currently: 2")

# Exercise 5.
add_executable(prime_factors prime_factors.cpp)
add_test(NAME test_prime_factors_1
  COMMAND /bin/bash -c "echo '15485867' | ./prime_factors")
set_tests_properties(test_prime_factors_1
  PROPERTIES PASS_REGULAR_EXPRESSION "15485867")
add_test(NAME test_prime_factors_2
  COMMAND /bin/bash -c "echo '2' | ./prime_factors")
set_tests_properties(test_prime_factors_2
  PROPERTIES PASS_REGULAR_EXPRESSION "2")
add_test(NAME test_prime_factors_3
  COMMAND /bin/bash -c "echo '45' | ./prime_factors")
set_tests_properties(test_prime_factors_3
  PROPERTIES PASS_REGULAR_EXPRESSION "3 5")
