//
// Created by Peter Lucia on 3/28/22.
//

#ifndef MYPROJECT_TIME_FORMATTER_H
#define MYPROJECT_TIME_FORMATTER_H

#include <date/date.h>
#include <date/tz.h>
#include <chrono>
#include <sstream>

using date::sys_time;
using date::parse;
using date::format;
using date::make_zoned;
using date::zoned_time;
using std::istringstream;
using std::chrono::microseconds;

class TimeFormatter {

public:
    /*
     * Converts utc time to a desired timezone
     *
     * Example:
     *      Input: "2022-03-30T05:18:14.660921+0000";
     *      Output: "2022-03-29T22:18:14.660921-0700";
     * References
     *      https://github.com/HowardHinnant/date/blob/master/include/date/date.h
     *      https://github.com/HowardHinnant/date
     *      https://en.cppreference.com/w/cpp/chrono/parse
     */
    static string utc_to_local_time(const string &utc_time, string desired_timezone = "US/Pacific") {
        istringstream stream{utc_time.c_str()};
        sys_time<microseconds> tp;
        stream >> parse("%FT%T%z", tp);
        auto zoned_datetime_utc = make_zoned("UTC", tp);
        auto zoned_datetime_output = make_zoned(desired_timezone, zoned_datetime_utc);
        return format("%FT%T%z", zoned_datetime_output);
    }

};

#endif //MYPROJECT_TIME_FORMATTER_H
