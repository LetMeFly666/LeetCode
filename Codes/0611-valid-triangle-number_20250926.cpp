/*
 * @Author: LetMeFly
 * @Date: 2025-09-26 22:40:03
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-09-26 22:44:19
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int ans = 0;
        sort(nums.begin(), nums.end());
        for (int i = nums.size() - 1; i >= 0; i--) {
            for (int l = 0, r = i - 1; l < r;) {
                if (nums[l] + nums[r] > nums[i]) {
                    ans += r - l;
                    r--;
                } else {
                    l++;
                }
            }
        }
        return ans;
    }
};