//
// Created by Peter Lucia on 1/24/22.
//

#ifndef TWO_SUM_H
#define TWO_SUM_H

#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <iostream>

using std::vector;
using std::unordered_map;
using std::unordered_set;
using std::cout;

namespace utils {


    void printVector(const vector<int> &v) {

        cout << "result: ";
        for (int val : v) {
            cout << val << ",";
        }
        cout << "\n";
    }

    void addVectorToSet(const vector<int> &v, unordered_set<int> &s) {
        for (const int &val : v) {
            s.insert(val);
        }
    }

    unordered_set<int> getSetFromVector(const vector<int> &v) {
        unordered_set<int> result;
        for (const int &val : v) {
            result.insert(val);
        }
        return result;
    }

}

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

#endif //TWO_SUM_H
