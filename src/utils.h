//
// Created by Peter Lucia on 2/17/22.
//

#ifndef MYPROJECT_UTILS_H
#define MYPROJECT_UTILS_H

#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <iostream>

using std::vector;
using std::unordered_map;
using std::unordered_set;
using std::cout;
using std::string;


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

    void prefix_trim(string &s, char char_to_trim) {
        s.erase(0, s.find_first_not_of(char_to_trim));
    }

    void suffix_trim(string &s, char char_to_trim) {
        s.erase(s.find_last_not_of(char_to_trim)+1);
    }

}

#endif //MYPROJECT_UTILS_H
