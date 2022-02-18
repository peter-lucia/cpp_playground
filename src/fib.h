//
// Created by Peter Lucia on 2/17/22.
//

#ifndef MYPROJECT_FIB_H
#define MYPROJECT_FIB_H

class Fib {
public:
    int fib(int n) {

        int a = 0;
        int b = 1;

        if (n == 0)
            return a;

        for (int i = 1; i < n; ++i)
        {
            int tmp = b;
            b += a;
            a = tmp;
        }
        return b;
    }
};


#endif //MYPROJECT_FIB_H
