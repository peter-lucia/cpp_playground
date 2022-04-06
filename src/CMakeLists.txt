add_library(misc
        two_sum.h
        utils.h
        fib.h
        remove_k_digits.h
        majority_element.h
        algorithms.h
        find_duplicate.h)

# https://github.com/HowardHinnant/date/blob/master/CMakeLists.txt
include(FetchContent)

FetchContent_Declare(date_src
	GIT_REPOSITORY https://github.com/HowardHinnant/date.git
	GIT_TAG        v3.0.1
)
FetchContent_MakeAvailable(date_src)

target_link_libraries(misc PRIVATE gtest gtest_main date::date-tz)

add_library(utils utils.h)

target_link_libraries(utils PRIVATE gtest gtest_main date::date-tz)
