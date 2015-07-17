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
  COMMAND /bin/bash -c "echo example input | ./mimic")
set_tests_properties(test_mimic_1
  PROPERTIES PASS_REGULAR_EXPRESSION "example input")
add_test(NAME test_mimic_2
  COMMAND /bin/bash -c "echo ' input with spaces ' | ./mimic")
set_tests_properties(test_mimic_2
  PROPERTIES PASS_REGULAR_EXPRESSION " input with spaces ")
add_test(NAME test_mimic_3
  COMMAND /bin/bash -c "echo ' ' | ./mimic")
set_tests_properties(test_mimic_3
  PROPERTIES PASS_REGULAR_EXPRESSION " ")
add_test(NAME test_mimic_4
  COMMAND /bin/bash -c
  "diff <(echo 'one two') <(echo 'one two' | ./mimic); echo $?")
set_tests_properties(test_mimic_4
  PROPERTIES PASS_REGULAR_EXPRESSION "0")
add_test(NAME test_mimic_5
  COMMAND /bin/bash -c
  "diff <(echo -e '\ntest\n') <(echo -e '\ntest\n' | ./mimic); echo $?")
set_tests_properties(test_mimic_5
  PROPERTIES PASS_REGULAR_EXPRESSION "0")

# Exercise 2.
add_executable(word_count word_count.cpp)
add_test(NAME test_word_count_1
  COMMAND /bin/bash -c "echo '' | ./word_count")
set_tests_properties(test_word_count_1
  PROPERTIES PASS_REGULAR_EXPRESSION "0")
add_test(NAME test_word_count_2
  COMMAND /bin/bash -c "echo example input | ./word_count")
set_tests_properties(test_word_count_2
  PROPERTIES PASS_REGULAR_EXPRESSION "2")
add_test(NAME test_word_count_3
  COMMAND /bin/bash -c "echo ' _ _ ' | ./word_count")
set_tests_properties(test_word_count_3
  PROPERTIES PASS_REGULAR_EXPRESSION "2")
add_test(NAME test_word_count_4
  COMMAND /bin/bash -c "echo -e 'test\ntest\ntest\n' | ./word_count")
set_tests_properties(test_word_count_4
  PROPERTIES PASS_REGULAR_EXPRESSION "3")

# Exercise 3.
add_executable(ternary ternary.cpp)
add_test(NAME test_ternary_1
  COMMAND /bin/bash -c "echo 0 | ./ternary | xargs printf \"%.3f\"")
set_tests_properties(test_ternary_1
  PROPERTIES PASS_REGULAR_EXPRESSION "0.000")
add_test(NAME test_ternary_2
  COMMAND /bin/bash -c "echo 10 | ./ternary | xargs printf \"%.3f\"")
set_tests_properties(test_ternary_2
  PROPERTIES PASS_REGULAR_EXPRESSION "3.000")
add_test(NAME test_ternary_3
  COMMAND /bin/bash -c "echo 102.11 | ./ternary | xargs printf \"%.3f\"")
set_tests_properties(test_ternary_3
  PROPERTIES PASS_REGULAR_EXPRESSION "11.444")
add_test(NAME test_ternary_4
  COMMAND /bin/bash -c "echo 11111.22222 | ./ternary | xargs printf \"%.3f\"")
set_tests_properties(test_ternary_4
  PROPERTIES PASS_REGULAR_EXPRESSION "121.996")
add_test(NAME test_ternary_5
  COMMAND /bin/bash -c "echo 1.1.1 | ./ternary")
set_tests_properties(test_ternary_5 PROPERTIES WILL_FAIL true)
add_test(NAME test_ternary_6
  COMMAND /bin/bash -c "echo 11111.22223 | ./ternary")
set_tests_properties(test_ternary_6 PROPERTIES WILL_FAIL true)
add_test(NAME test_ternary_7
  COMMAND /bin/bash -c "echo success | ./ternary")
set_tests_properties(test_ternary_7 PROPERTIES WILL_FAIL true)

# Exercise 4.
add_executable(stack_lang stack_lang.cpp)
add_test(NAME test_stack_lang_1
  COMMAND /bin/bash -c "echo 1 | ./stack_lang")
set_tests_properties(test_stack_lang_1 PROPERTIES WILL_FAIL false)
add_test(NAME test_stack_lang_2
  COMMAND /bin/bash -c "echo -e '\n1 print\n' | ./stack_lang")
set_tests_properties(test_stack_lang_2
  PROPERTIES PASS_REGULAR_EXPRESSION "--> Stack: 1")
add_test(NAME test_stack_lang_3
  COMMAND /bin/bash -c "echo '1 print print' | ./stack_lang")
set_tests_properties(test_stack_lang_3
  PROPERTIES PASS_REGULAR_EXPRESSION "--> Stack: 1 \n--> Stack: 1")
add_test(NAME test_stack_lang_4
  COMMAND /bin/bash -c "echo '1 2 *' | ./stack_lang")
set_tests_properties(test_stack_lang_4 PROPERTIES WILL_FAIL false)
add_test(NAME test_stack_lang_5
  COMMAND /bin/bash -c "echo ' 1 2 - print ' | ./stack_lang")
set_tests_properties(test_stack_lang_5
  PROPERTIES PASS_REGULAR_EXPRESSION "--> Stack: -1")
add_test(NAME test_stack_lang_6
  COMMAND /bin/bash -c "echo '1 print 2 print / print' | ./stack_lang")
set_tests_properties(test_stack_lang_6
  PROPERTIES PASS_REGULAR_EXPRESSION
  "--> Stack: 1 \n--> Stack: 1 2 \n--> Stack: 0")
add_test(NAME test_stack_lang_7
  COMMAND /bin/bash -c "echo '1 print print 2 print print +' | ./stack_lang")
set_tests_properties(test_stack_lang_7 PROPERTIES WILL_FAIL false)
add_test(NAME test_stack_lang_8
  COMMAND /bin/bash -c "echo '1 2 + 1 2 - * print' | ./stack_lang")
set_tests_properties(test_stack_lang_8
  PROPERTIES PASS_REGULAR_EXPRESSION "--> Stack: -3")
add_test(NAME test_stack_lang_9
  COMMAND /bin/bash -c "echo print | ./stack_lang")
set_tests_properties(test_stack_lang_9 PROPERTIES WILL_FAIL true)
add_test(NAME test_stack_lang_10
  COMMAND /bin/bash -c "echo print print | ./stack_lang")
set_tests_properties(test_stack_lang_10 PROPERTIES WILL_FAIL true)
add_test(NAME test_stack_lang_11
  COMMAND /bin/bash -c "echo '+' | ./stack_lang")
set_tests_properties(test_stack_lang_11 PROPERTIES WILL_FAIL true)
add_test(NAME test_stack_lang_12
  COMMAND /bin/bash -c "echo '1 -' | ./stack_lang")
set_tests_properties(test_stack_lang_12 PROPERTIES WILL_FAIL true)
add_test(NAME test_stack_lang_13
  COMMAND /bin/bash -c "echo '* *' | ./stack_lang")
set_tests_properties(test_stack_lang_13 PROPERTIES WILL_FAIL true)
add_test(NAME test_stack_lang_14
  COMMAND /bin/bash -c "echo '1 2' | ./stack_lang")
set_tests_properties(test_stack_lang_14 PROPERTIES WILL_FAIL true)
add_test(NAME test_stack_lang_15
  COMMAND /bin/bash -c "echo '1 2 3 /' | ./stack_lang")
set_tests_properties(test_stack_lang_15 PROPERTIES WILL_FAIL true)

# Exercise 5.
add_executable(prime_factors prime_factors.cpp)
add_test(NAME test_prime_factors_1
  COMMAND /bin/bash -c "echo 15485867 | ./prime_factors")
set_tests_properties(test_prime_factors_1
  PROPERTIES PASS_REGULAR_EXPRESSION "15485867")
add_test(NAME test_prime_factors_2
  COMMAND /bin/bash -c "echo 2 | ./prime_factors")
set_tests_properties(test_prime_factors_2
  PROPERTIES PASS_REGULAR_EXPRESSION "2")
add_test(NAME test_prime_factors_3
  COMMAND /bin/bash -c "echo 45 | ./prime_factors")
set_tests_properties(test_prime_factors_3
  PROPERTIES PASS_REGULAR_EXPRESSION "3 5")
add_test(NAME test_prime_factors_4
  COMMAND /bin/bash -c "echo 1 | ./prime_factors")
set_tests_properties(test_prime_factors_4 PROPERTIES WILL_FAIL true)
add_test(NAME test_prime_factors_5
  COMMAND /bin/bash -c "echo success | ./prime_factors")
set_tests_properties(test_prime_factors_5 PROPERTIES WILL_FAIL true)
