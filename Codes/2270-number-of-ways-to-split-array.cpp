/*
 * @Author: LetMeFly
 * @Date: 2025-01-13 22:28:42
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-01-13 22:31:22
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        vector<long long> prefix(nums.size());
        prefix[0] = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            prefix[i] = prefix[i - 1] + nums[i];
        }
        int ans = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            ans += prefix[i] >= prefix.back() - prefix[i];
        }
        return ans;
    }
};