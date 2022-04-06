//
// Created by Peter Lucia on 3/28/22.
//

#ifndef MYPROJECT_TIME_FORMATTER_H
#define MYPROJECT_TIME_FORMATTER_H

#include <iostream>
#include <string>
#include <ctime>
#include "boost/date_time/posix_time/posix_time.hpp"
#include "boost/date_time/local_time_adjustor.hpp"
#include "boost/date_time/c_local_time_adjustor.hpp"
#include "boost/date_time/local_time/local_time.hpp"
#include "boost/date_time/time_facet.hpp"
#include <locale>
#include <stdio.h>

// std
using std::string;
using std::stringstream;
using std::tm;
using std::locale;
using std::istringstream;

// boost
using boost::date_time::not_a_date_time;
using boost::posix_time::ptime;
using boost::posix_time::hours;
using boost::posix_time::no_dst;
using boost::posix_time::time_from_string;
using boost::posix_time::from_iso_string;
using boost::posix_time::us_dst;
using boost::posix_time::time_input_facet;
using boost::gregorian::May;
using boost::gregorian::date;
using boost::gregorian::to_simple_string;
using boost::local_time::local_date_time;
using boost::local_time::local_time_facet;
using boost::local_time::local_time_input_facet;

class TimeFormatter {

public:
    /*
     * Converts an isoformatted, timezone aware datetime string to local time
     * Example:
     *      Input: "2022-03-30T05:18:14.660921+00:00";
     *      Output: "2022-03-29T22:18:14.660921-07:00";
     * References
     *      https://www.boost.org/doc/libs/1_78_0/doc/html/date_time.html
     *      https://www.boost.org/doc/libs/1_78_0/doc/html/date_time/examples.html#date_time.examples.local_utc_conversion
     *      https://en.cppreference.com/w/cpp/chrono/parse
     *      https://stackoverflow.com/questions/26901009/boost-how-to-parse-following-string-to-date-time
     *      https://www.cplusplus.com/reference/ctime/strftime/
     */
    string convert_isoformatted_time(const string &utc_time, string output_offset = "+00:00") {

        unsigned int year = 0;
        unsigned int month = 0;
        unsigned int day = 0;
        unsigned int hour = 0;
        unsigned int minute = 0;
        float second = 0;
        int offset_hours = 0;
        unsigned int offset_minutes = 0;
        char sign_of_offset = '+';

        string c_fmt = "%04u-%02u-%02uT%02u:%02u:%f%c%02d:%02u";
        sscanf(utc_time.c_str(), c_fmt.c_str(), &year, &month, &day, &hour, &minute, &second, &sign_of_offset, &offset_hours,
               &offset_minutes);

        int offset_operator = 1;
        if (sign_of_offset == '-')
            offset_operator = -1;

        long offset_seconds = offset_operator*offset_hours/(60*60)
                + offset_operator*offset_minutes/60; // gmt off is in seconds.

        std::tm t;
        t.tm_year = year;
        t.tm_mon = month;
        t.tm_mday = day;
        t.tm_hour = hour;
        t.tm_min = minute;
        t.tm_sec = second;
        t.tm_gmtoff = offset_seconds;

        std::time_t seconds_since_epoch = mktime(&t);

        char sign_of_output_offset = '+';
        unsigned int output_offset_hours = 0;
        unsigned int output_offset_minutes = 0;

        sscanf(output_offset.c_str(),
               "%c%02u:%02u",
               &sign_of_output_offset,
               &output_offset_hours,
               &output_offset_minutes);

        int output_offset_operator = 1;
        if (sign_of_output_offset == '-')
            output_offset_operator = -1;

        long output_offset_seconds = output_offset_operator*output_offset_hours/(60*60)
                + output_offset_operator*output_offset_minutes/60; // gmt off is in seconds.

        seconds_since_epoch += output_offset_seconds;

        auto ymd = date::year_month_day{seconds_since_epoch};

        // https://www.cplusplus.com/reference/cstdio/printf/
        char output[1024];
        snprintf(output, sizeof(output), "%04u-%02u-%02uT%02u:%02u:%.6f%c%02u:%02u",
                 year,
                 month,
                 day,
                 hour,
                 minute,
                 second,
                 offset_char,
                 (tm_gmtoff_minutes % 24),
                 ((tm_gmtoff_minutes % 24) % 60)
                 );
        return output;

    }

};

#endif //MYPROJECT_TIME_FORMATTER_H
