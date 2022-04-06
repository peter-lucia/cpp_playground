include(FetchContent)

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        release-1.11.0
)
FetchContent_MakeAvailable(googletest)


add_executable(mytest test_algorithms.cc)
target_link_libraries(mytest PRIVATE gtest gtest_main date::date-tz)
include(GoogleTest)
gtest_discover_tests(mytest)

# must run brew install boost
# list libraries that are needed,
# they can be found here: https://www.boost.org/doc/libs/
find_package(
        Boost 1.78 REQUIRED
        COMPONENTS date_time
)

if(Boost_FOUND)
    message("Boost found")
    include_directories(${Boost_INCLUDE_DIRS})
#    target_link_libraries(mytest ${Boost_LIBRARIES})
else()
    message("Boost not found")
endif()




