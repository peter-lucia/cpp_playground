//
// Created by Peter Lucia on 3/28/22.
//

#ifndef MYPROJECT_TIME_FORMATTER_H
#define MYPROJECT_TIME_FORMATTER_H

#include <iostream>
#include <string>
#include "boost/date_time/posix_time/posix_time.hpp"
#include "boost/date_time/local_time_adjustor.hpp"
#include "boost/date_time/c_local_time_adjustor.hpp"

using std::string;
using std::tm;
using boost::posix_time::ptime;
using boost::posix_time::hours;
using boost::posix_time::no_dst;
using boost::posix_time::time_from_string;
using boost::posix_time::from_iso_string;
using boost::posix_time::us_dst;
using boost::gregorian::May;
using boost::gregorian::date;
using boost::gregorian::to_simple_string;

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
     */
    static string convert_isoformatted_time(const string &provided_time) {
        boost::date_time::local_adjustor<ptime, -8, us_dst> us_california;
        ptime utc_time = time_from_string(provided_time);

        ptime local_time = us_california.utc_to_local(utc_time);
        return to_simple_string(local_time);
    }

};

#endif //MYPROJECT_TIME_FORMATTER_H
