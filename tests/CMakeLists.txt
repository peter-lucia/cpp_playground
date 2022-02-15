add_executable(mytest test_two_sum.h)
target_link_libraries(mytest gtest gtest_main)
include(GoogleTest)
gtest_discover_tests(mytest)

# Extra linking for the project.
#target_link_libraries(mytest main)


