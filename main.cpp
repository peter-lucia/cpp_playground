#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
#include <unordered_set>
#include "two_sum.h"

using namespace std;


int doTwoSum() {
    std::cout << "Hello, World!" << std::endl;
    vector<int> vals = {2,3,4,5,7};
    int target = 9;
    TwoSum s;
    vector<int> result = s.twoSum(vals, target);
    for (int num : result)
    {
        std::cout << num;
    }

    return 0;
}


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

int doFib() {
    Fib f;
    cout << f.fib(3);
}

class FizzBuzz {
public:
    vector<string> fizzBuzz(int n) {
        // multiples of 3 output Fizz
        // multiples of 5 output Buzz
        // multiples of both 3 and 5 output Buzz
        vector<string> result;
        for (int i = 1; i <= n; ++i)
        {
            string s = to_string(i);
            if (i % 3 == 0) {
                s = "Fizz";
            }
            if (i % 5 == 0) {
                if (s == "Fizz")
                    s.append("Buzz");
                else
                    s = "Buzz";
            }
            result.push_back(s);
        }
        return result;
    }
};

int main2() {
    FizzBuzz fb;
    vector<string> result = fb.fizzBuzz(15);
    for (const string &val : result)
        cout << val << " ";
}

class NumIslands {
private:
    vector<vector<char>> grid;
    int rows;
    int cols;
    int total_visited = 0;
    bool found_start = false;
    int i_start = 0;
    int j_start = 0;
    int total_ones = 0;
    vector<vector<bool>> visited;
    unordered_multimap<int, int> positions_to_visit;
public:

    void print_positions_to_visit()
    {
        cout << "{";
        auto it = positions_to_visit.begin();
        while (it != positions_to_visit.end())
        {
            cout << "(" << (*it).first << ", " << (*it).second << "), ";
            ++it;
        }
        cout << "}\n";
    }

    void delete_from_positions_to_visit(const int &i, const int &j)
    {
        auto it = positions_to_visit.begin();
        while (it != positions_to_visit.end())
        {
            if ((*it).first == i && (*it).second == j) {
//                cout << "deleting " << (*it).first << ", " << (*it).second << "\n";
                positions_to_visit.erase(it++);
            }
            else
                ++it;
        }
    }

    void explore(const int &i, const int &j) {
        if (grid[i][j] == '0')
            return;
        if (visited[i][j])
            return;
        // mark the position as visited
        this->visited[i][j] = true;

        delete_from_positions_to_visit(i,j);
        cout << "Visiting (" << i << ", " << j << ")\n";

        // increment total visited
        ++this->total_visited;
        if (i > 0 && !visited[i-1][j]) {
            explore(i-1, j);
        }
        if ( i < (rows - 1) && !visited[i+1][j]) {
            explore(i+1, j);
        }
        if (j > 0 && !visited[i][j-1]) {
            explore(i, j-1);
        }
        if (j < (cols - 1) && !visited[i][j+1]) {
            explore(i, j+1);
        }
        // can't explore anymore
        return;
    }
    int numIslands(vector<vector<char>>& grid) {
        this->grid = grid;
        rows = grid.size();
        cols = grid[0].size();
        int total_islands = 0;
        // count ones,
        for (int i = 0; i < rows; ++i) {
            // construct visited 2D array (rows)
            vector<bool> tmp;
            visited.push_back(tmp);
            for (int j = 0; j < cols; ++j) {
                // construct visited 2D array (columns)
                visited[i].push_back(false);
                if (grid[i][j] == '1') {
                    // add this position to the multimap of positions we need to visit
                    positions_to_visit.insert({i, j});
                    // set i_start and j_start when we first find a 1
                    if (!found_start) {
                        i_start = i;
                        j_start = j;
                        found_start = true;
                    }

                    ++total_ones;
                }
            }
        }

        cout << "Found " << total_ones << " ones. \n";

        // start exploring from the first found 1
        if (total_ones > 0) {
            while (positions_to_visit.size() > 0) {
                cout << "Exploring from " << i_start << ", " << j_start << "\n";
//                print_positions_to_visit();
                if (positions_to_visit.size() > 0) {
                    i_start = positions_to_visit.begin()->first;
                    j_start = positions_to_visit.begin()->second;
                    delete_from_positions_to_visit(i_start, j_start);
                }
                explore(i_start, j_start);
                ++total_islands;
            }
        } else {
            return 0;
        }
        return total_islands;

    }
};


int main() {
    NumIslands numIslands;
//    vector<vector<char>> grid {
//            {'1','1','1','1','0'},
//            {'1','1','0','1','0'},
//            {'1','1','0','0','0'},
//            {'0','0','0','0','0'}
//    };
//    int result = numIslands.numIslands(grid);
//    cout << "num islands: " << result << "\n";

    vector<vector<char>> grid {
            {'1','1','0','0','0'},
            {'1','1','0','0','0'},
            {'0','0','1','0','0'},
            {'0','0','0','1','1'}
    };
    int result = numIslands.numIslands(grid);
    cout << "num islands: " << result << "\n";
}