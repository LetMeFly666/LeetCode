/*
 * @Author: LetMeFly
 * @Date: 2026-04-10 23:22:00
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-04-10 23:25:26
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int ans = 201;
        for (int i = 0, n = nums.size(); i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (nums[j] != nums[i]) {
                    continue;
                }
                for (int k = j + 1; k < n; k++) {
                    if (nums[k] == nums[i]) {
                        ans = min(ans, 2 * (k - i));
                    }
                }
            }
        }
        return ans == 201 ? -1 : ans;
    }
};
