/*
 * @Author: LetMeFly
 * @Date: 2024-06-15 19:05:51
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-06-15 19:06:55
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        int ans = 1;
        sort(nums.begin(), nums.end());
        k *= 2;
        for (int l = 0, r = 0; r < nums.size(); r++) {
            while (nums[r] - nums[l] > k) {
                l++;
            }
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};