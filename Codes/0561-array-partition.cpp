/*
 * @Author: LetMeFly
 * @Date: 2023-03-15 10:42:11
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-03-15 10:42:11
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = 0;
        for (int i = 0; i < nums.size(); i += 2) {
            ans += nums[i];
        }
        return ans;
    }
};