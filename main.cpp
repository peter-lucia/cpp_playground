#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
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

int main() {
    std::cout << "Hello, World!" << std::endl;
    vector<int> vals = {2,3,4,5,7};
    int target = 9;
    Solution s;
    vector<int> result = s.twoSum(vals, target);
    for (int num : result)
    {
        std::cout << num;
    }

    return 0;
}
