//
// Created by Peter Lucia on 2/20/22.
//

#ifndef MYPROJECT_MAJORITY_ELEMENT_H
#define MYPROJECT_MAJORITY_ELEMENT_H
#include <unordered_map>

using std::unordered_map;


int majorityElement(vector<int> &nums) {
    unordered_map<int, int> lookup;

    int max_elem = nums[0];
    int max_elem_counts = 0;

    for (const int &num : nums) {
        if (lookup.find(num) != lookup.end()) {
            lookup[num] += 1;
        } else {
            lookup[num] = 1;
        }

        if (lookup[num] > max_elem_counts) {
            max_elem = num;
            max_elem_counts = lookup[num];
        }

    }

    utils::print_unordered_map(lookup);

    return max_elem;

}


#endif //MYPROJECT_MAJORITY_ELEMENT_H
