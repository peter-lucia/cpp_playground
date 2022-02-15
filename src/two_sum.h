//
// Created by Peter Lucia on 1/24/22.
//

#ifndef LEETCODE_CPP_TWO_SUM_H
#define LEETCODE_CPP_TWO_SUM_H

#include <vector>
#include <unordered_map>
using std::vector;
using std::unordered_map;

class TwoSum {
public:
    vector<int> twoSum(const vector<int>& nums, const int target) {
        // maps numbers to their indexes
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (map.find(target - nums[i]) != map.end())
                return {i, map[target-nums[i]]};
            map[nums[i]] = i;
        }
        return {-1, -1};
    }
};

#endif //LEETCODE_CPP_TWO_SUM_H
