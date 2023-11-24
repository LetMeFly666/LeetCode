/*
 * @Author: LetMeFly
 * @Date: 2023-11-24 10:03:07
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-11-24 11:03:27
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int ans = 0;
        for (vector<int>::iterator it = nums.begin(); it != nums.end(); it++) {
            ans += lower_bound(nums.begin(), it, target - *it) - nums.begin();
        }
        return ans;
    }
};