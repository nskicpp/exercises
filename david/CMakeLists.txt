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
add_executable(poor_mans_cat poor_mans_cat.cpp)
add_executable(wordcounter wordcounter.cpp)
add_executable(trinary trinary.cpp)
add_executable(stack_language stack_language.cpp)
add_executable(prime_factors prime_factors.cpp)

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

add_test(NAME test_wordcounter0 COMMAND /bin/sh -c "echo A and B and C | ./wordcounter")
set_tests_properties(test_wordcounter0
  PROPERTIES PASS_REGULAR_EXPRESSION "5")
add_test(NAME test_wordcounter1 COMMAND /bin/sh -c "echo | ./wordcounter")
set_tests_properties(test_wordcounter1
  PROPERTIES PASS_REGULAR_EXPRESSION "0")
add_test(NAME test_wordcounter2 COMMAND /bin/sh -c "echo dashed-words punctuation? ? | ./wordcounter")
set_tests_properties(test_wordcounter2
  PROPERTIES PASS_REGULAR_EXPRESSION "3")
add_test(NAME test_wordcounter3 COMMAND /bin/sh -c "echo '\nA word \n More  words\ttab-separated' | ./wordcounter")
set_tests_properties(test_wordcounter3
  PROPERTIES PASS_REGULAR_EXPRESSION "5")

add_test(NAME test_trinary0 COMMAND /bin/sh -c "echo 10 | ./trinary")
set_tests_properties(test_trinary0
  PROPERTIES PASS_REGULAR_EXPRESSION "3")
add_test(NAME test_trinary1 COMMAND /bin/sh -c "echo ' 120\n' | ./trinary")
set_tests_properties(test_trinary1
  PROPERTIES PASS_REGULAR_EXPRESSION "15")
add_test(NAME test_trinary2 COMMAND /bin/sh -c "echo | ./trinary")
set_tests_properties(test_trinary2 PROPERTIES WILL_FAIL true)
add_test(NAME test_trinary3 COMMAND /bin/sh -c "echo 14 | ./trinary")
set_tests_properties(test_trinary3 PROPERTIES WILL_FAIL true)
add_test(NAME test_trinary4 COMMAND /bin/sh -c "echo '10 ' | ./trinary")
set_tests_properties(test_trinary4 PROPERTIES PASS_REGULAR_EXPRESSION "3")

add_test(NAME test_stack_language0 COMMAND /bin/sh -c "echo 10 10 + print | ./stack_language")
set_tests_properties(test_stack_language0
  PROPERTIES PASS_REGULAR_EXPRESSION "20")
add_test(NAME test_stack_language1 COMMAND /bin/sh -c "echo 42 print 42 print + | ./stack_language")
set_tests_properties(test_stack_language1
  PROPERTIES PASS_REGULAR_EXPRESSION ".*42.*42.*")
add_test(NAME test_stack_language2 COMMAND /bin/sh -c "echo 10 10 - print | ./stack_language")
set_tests_properties(test_stack_language2
  PROPERTIES PASS_REGULAR_EXPRESSION "0")
add_test(NAME test_stack_language3 COMMAND /bin/sh -c "echo '10 10 * print' | ./stack_language")
set_tests_properties(test_stack_language3
  PROPERTIES PASS_REGULAR_EXPRESSION "100")
add_test(NAME test_stack_language4 COMMAND /bin/sh -c "echo 10 10 / print | ./stack_language")
set_tests_properties(test_stack_language4
  PROPERTIES PASS_REGULAR_EXPRESSION "1")
add_test(NAME test_stack_language5 COMMAND /bin/sh -c "echo 10 10 / 2 + print | ./stack_language")
set_tests_properties(test_stack_language5
  PROPERTIES PASS_REGULAR_EXPRESSION "3")
add_test(NAME test_stack_language_fail0 COMMAND /bin/sh -c "echo asdf | ./stack_language")
set_tests_properties(test_stack_language_fail0 PROPERTIES WILL_FAIL true)
add_test(NAME test_stack_language_fail1 COMMAND /bin/sh -c "echo 20 + | ./stack_language")
set_tests_properties(test_stack_language_fail1 PROPERTIES WILL_FAIL true)
add_test(NAME test_stack_language_fail2 COMMAND /bin/sh -c "echo 20 20 - + | ./stack_language")
set_tests_properties(test_stack_language_fail2 PROPERTIES WILL_FAIL true)
add_test(NAME test_stack_language_fail3 COMMAND /bin/sh -c "echo 1 3 print | ./stack_language")
set_tests_properties(test_stack_language_fail3 PROPERTIES WILL_FAIL true)

add_test(NAME test_prime_factors0 COMMAND /bin/sh -c "echo 10 | ./prime_factors")
set_tests_properties(test_prime_factors0
  PROPERTIES PASS_REGULAR_EXPRESSION "2 5")
add_test(NAME test_prime_factors1 COMMAND /bin/sh -c "echo 41 | ./prime_factors")
set_tests_properties(test_prime_factors1
  PROPERTIES PASS_REGULAR_EXPRESSION "41")
add_test(NAME test_prime_factors2 COMMAND /bin/sh -c "echo 34 | ./prime_factors")
set_tests_properties(test_prime_factors2 PROPERTIES PASS_REGULAR_EXPRESSION "2 17")
add_test(NAME test_prime_factors3 COMMAND /bin/sh -c "echo 120 | ./prime_factors")
set_tests_properties(test_prime_factors3 PROPERTIES PASS_REGULAR_EXPRESSION "2 3 5")
add_test(NAME test_prime_factors4 COMMAND /bin/sh -c "echo 0 | ./prime_factors")
set_tests_properties(test_prime_factors4
  PROPERTIES PASS_REGULAR_EXPRESSION "no prime factors")
add_test(NAME test_prime_factors5 COMMAND /bin/sh -c "echo 1 | ./prime_factors")
set_tests_properties(test_prime_factors5
  PROPERTIES PASS_REGULAR_EXPRESSION "no prime factors")
