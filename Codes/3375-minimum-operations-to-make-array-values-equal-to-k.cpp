/*
 * @Author: LetMeFly
 * @Date: 2025-04-09 21:58:45
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-04-09 22:08:39
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end(), greater<int>());
        if (nums.back() < k) {
            return -1;
        }
        int ans = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[i - 1]) {
                printf("nums[%d] = %d, nums[%d] = %d, ans = %d, ans++\n", i, nums[i], i - 1, nums[i - 1], ans);  // ****
                ans++;
            }
        }
        return ans + (nums.back() != k);
    }
};