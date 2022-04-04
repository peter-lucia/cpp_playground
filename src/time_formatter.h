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
#include "boost/date_time/local_time/local_time.hpp"
#include "boost/date_time/time_facet.hpp"
#include <locale>

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
     */
    static string convert_isoformatted_time(const string &provided_time) {

        // specify desired timezone, hardcoded for now temporarily
        boost::date_time::local_adjustor<ptime, -8, us_dst> us_california;

        // rfc3339 datetime format definition
        const string fmt = "%Y-%m-%dT%H:%M:%s%Q";

        // format the input
        local_time_input_facet *input_facet = new local_time_input_facet(fmt);
        input_facet->format(fmt.c_str());
        const locale input_loc = locale(locale("en_US"), input_facet);
        stringstream input_ss(provided_time);
        input_ss.imbue(input_loc);
        input_ss.str("");
        input_ss << provided_time;

        // add provided time str to input ss
        ptime utc_time(not_a_date_time);
        input_ss >> utc_time;

        // perform timezone adjustment
        ptime local_time = us_california.utc_to_local(utc_time);

        // format the output
        local_time_facet* output_facet = new local_time_facet();
        output_facet->format(fmt.c_str());
        stringstream output_ss;

        const locale output_loc = locale(locale("en_US"), output_facet);
        output_ss.imbue(output_loc);
        output_ss.str("");
        output_ss << local_time;
        return output_ss.str();
    }

};

#endif //MYPROJECT_TIME_FORMATTER_H
