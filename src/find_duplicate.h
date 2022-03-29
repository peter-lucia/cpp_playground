//
// Created by Peter Lucia on 3/28/22.
//

#ifndef MYPROJECT_FIND_DUPLICATE_H
#define MYPROJECT_FIND_DUPLICATE_H

#include <vector>
#include <unordered_set>

using std::vector;


class FindDuplicate {
public:
    int findDuplicate(vector<int>& nums) {

        unordered_set<int> st;

        for (const int &n : nums) {
            if (st.find(n) != st.end()) {
                return n;
            }
            st.insert(n);
        }

        return -1;
    }
};

#endif //MYPROJECT_FIND_DUPLICATE_H
