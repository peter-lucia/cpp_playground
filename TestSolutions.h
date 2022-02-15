//
// Created by Peter Lucia on 1/24/22.
//

#ifndef LEETCODE_CPP_TESTSOLUTIONS_H
#define LEETCODE_CPP_TESTSOLUTIONS_H

#include "TwoSum.h"
using std::vector;


class TestSolutions {
    bool testTwoSum() {
        vector<int> v = {1,2,6,7};
        vector<int> result = {1,3};
        return TwoSum().twoSum(v, 9) == result;
    }

};


#endif //LEETCODE_CPP_TESTSOLUTIONS_H
