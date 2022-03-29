add_library(two_sum two_sum.h utils.h fib.h remove_k_digits.h majority_element.h algorithms.h find_duplicate.h)
add_library(utils utils.h)
target_link_libraries(two_sum gtest gtest_main)
target_link_libraries(utils gtest gtest_main)
