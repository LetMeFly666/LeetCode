/*
 * @Author: LetMeFly
 * @Date: 2026-04-13 21:39:33
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-04-13 21:40:13
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int ans = nums.size();
        for (int i = 0, n = nums.size(); i < n; i++) {
            if (nums[i] == target) {
                ans = min(ans, abs(i - start));
            }
        }
        return ans;
    }
};