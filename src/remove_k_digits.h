//
// Created by Peter Lucia on 2/17/22.
//

#ifndef MYPROJECT_REMOVE_K_DIGITS_H
#define MYPROJECT_REMOVE_K_DIGITS_H

#include <stack>
using std::string;
using std::max;
using std::stack;

class RemoveKDigits {
public:
    string removeKdigits(string num, int k) {

        // We can remove all digits
        if (k >= num.size()) {
            return "0";
        }

        // iterate over all digits
        // push each character to the stack
        // prefix trim
        stack<char> _stack;

        for (const char &c : num) {

            // if the character at the top of the stack > current digit
            // pop it from the stack
            while (!_stack.empty() && k > 0 && _stack.top() - '0' > c - '0') {
                _stack.pop();
                k -= 1;
            }
            _stack.push(c);
        }

        // remove any left over elements from the end of the resultant word
        // note that the end of the resultant word is the top of the stack
        for (int i = 0; i < k; ++i) {
            if (!_stack.empty())
                _stack.pop();
        }

        stack<char> _stack_tmp;
        while (!_stack.empty()) {
            _stack_tmp.push(_stack.top());
            _stack.pop();
        }

        string result;
        while (!_stack_tmp.empty()) {
            result.push_back(_stack_tmp.top());
            _stack_tmp.pop();
        }

        // remove leading zeros
        result.erase(0, result.find_first_not_of('0'));

        // ensure 0 is always returned
        if (result == "")
            return "0";
        return result;
    }
};

#endif //MYPROJECT_REMOVE_K_DIGITS_H
