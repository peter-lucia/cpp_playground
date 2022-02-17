include(FetchContent)

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        release-1.11.0
)
FetchContent_MakeAvailable(googletest)


add_executable(mytest test_two_sum.cc)
target_link_libraries(mytest gtest gtest_main)
include(GoogleTest)
gtest_discover_tests(mytest)




