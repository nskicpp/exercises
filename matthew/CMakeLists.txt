project(nskicpp-gharrma)
cmake_minimum_required(VERSION 3.1)

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

enable_testing()

# lesson 3
add_executable(hello_person hello_person.cpp)
add_test(NAME test_hello_person
  COMMAND "/bin/sh" "-c" "echo Matthew Gharrity | ./hello_person")
set_tests_properties(test_hello_person
  PROPERTIES PASS_REGULAR_EXPRESSION "Hello, Matthew Gharrity.")

# lesson 4
add_executable(echo echo.cpp)
add_test(NAME test_echo0
  COMMAND "/bin/sh" "-c" "echo -e 'test expression! asdf\n' | ./echo")
set_tests_properties(test_echo0
  PROPERTIES PASS_REGULAR_EXPRESSION "test expression! asdf\n")
add_test(NAME test_echo1
  COMMAND "/bin/sh" "-c" "echo -e '\n\n\tasdfasdf\n    \t\nb' | ./echo")
set_tests_properties(test_echo1
  PROPERTIES PASS_REGULAR_EXPRESSION "\n\n\tasdfasdf\n    \t\nb")

add_executable(word_count word_count.cpp)
add_test(NAME test_word_count0
  COMMAND "/bin/sh" "-c" 
          "echo another test expression! woot. | ./word_count")
set_tests_properties(test_word_count0
  PROPERTIES PASS_REGULAR_EXPRESSION "4")
add_test(NAME test_word_count1
  COMMAND "/bin/sh" "-c" 
          "echo 'a more complicated\t\n\ntext expression \nwith\
          a few more words and so a higher word count' | ./word_count")
set_tests_properties(test_word_count1
  PROPERTIES PASS_REGULAR_EXPRESSION "16")
  
add_executable(trinary_to_decimal trinary_to_decimal.cpp)
add_test(NAME test_trinary_to_decimal0
  COMMAND "/bin/sh" "-c" "echo 1201 | ./trinary_to_decimal")
set_tests_properties(test_trinary_to_decimal0
  PROPERTIES PASS_REGULAR_EXPRESSION "46")
add_test(NAME test_trinary_to_decimal1
  COMMAND "/bin/sh" "-c" "echo 0120.0120 | ./trinary_to_decimal")
set_tests_properties(test_trinary_to_decimal1
  PROPERTIES PASS_REGULAR_EXPRESSION "15.1852")

add_executable(stack_lang stack_lang.cpp)
add_test(NAME test_stack_lang0
  COMMAND "/bin/sh" "-c" "echo 1 90 5 7 11 9 - + \\* / print | ./stack_lang")
set_tests_properties(test_stack_lang0
  PROPERTIES PASS_REGULAR_EXPRESSION "1 2")
add_test(NAME test_stack_lang1
  COMMAND "/bin/sh" "-c" "echo 1 2 3 + + + print | ./stack_lang 2>&1")
set_tests_properties(test_stack_lang1
  PROPERTIES PASS_REGULAR_EXPRESSION "Input malformed.")
add_test(NAME test_stack_lang2
  COMMAND "/bin/sh" "-c" "echo 1 2 print + print | ./stack_lang 2>&1")
set_tests_properties(test_stack_lang2
  PROPERTIES PASS_REGULAR_EXPRESSION "1 2.*3")
add_test(NAME test_stack_lang3
  COMMAND "/bin/sh" "-c" "echo 1 2 3 | ./stack_lang 2>&1")
set_tests_properties(test_stack_lang3
  PROPERTIES PASS_REGULAR_EXPRESSION "Input malformed")

add_executable(prime_factors prime_factors.cpp)
add_test(NAME prime_factors_test0
  COMMAND "/bin/sh" "-c" "echo 1000007 | ./prime_factors")
set_tests_properties(prime_factors_test0
  PROPERTIES PASS_REGULAR_EXPRESSION "29 34483")
add_test(NAME prime_factors_test1
  COMMAND "/bin/sh" "-c" "echo 1 | ./prime_factors")
set_tests_properties(prime_factors_test1
  PROPERTIES PASS_REGULAR_EXPRESSION "[none]")
add_test(NAME prime_factors_test2
  COMMAND "/bin/sh" "-c" "echo 982451653 | ./prime_factors")
set_tests_properties(prime_factors_test2
  PROPERTIES PASS_REGULAR_EXPRESSION "982451653")
add_test(NAME prime_factors_test3
  COMMAND "/bin/sh" "-c" "echo 2 | ./prime_factors")
set_tests_properties(prime_factors_test3
  PROPERTIES PASS_REGULAR_EXPRESSION "2")
add_test(NAME prime_factors_test4
  COMMAND "/bin/sh" "-c" "echo 1024 | ./prime_factors")
set_tests_properties(prime_factors_test4
  PROPERTIES PASS_REGULAR_EXPRESSION "2")
add_test(NAME prime_factors_test5
  COMMAND "/bin/sh" "-c" "echo 3 | ./prime_factors")
set_tests_properties(prime_factors_test5
  PROPERTIES PASS_REGULAR_EXPRESSION "3")
