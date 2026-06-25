/*
 * @Author: LetMeFly
 * @Date: 2026-06-25 22:07:29
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-06-25 22:09:54
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int ans = 0;
        for (int i = 0, n = nums.size(); i < n; i++) {
            int cnt = 0;
            for (int j = i; j < n; j++) {
                cnt += nums[j] == target;
                ans += cnt * 2 > j - i + 1;
            }
        }
        return ans;
    }
};
