/*
 * @Author: LetMeFly
 * @Date: 2025-07-23 10:31:42
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-07-23 10:46:04
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_set<int> had;
        int ans = 0, cnt = 0;
        for (int l = 0, r = 0; r < nums.size(); r++) {
            if (had.count(nums[r])) {
                while (nums[l] != nums[r]) {
                    cnt -= nums[l++];
                }
            } else {
                had.insert(nums[r]);
            }
            cnt += nums[r];
            ans = max(ans, cnt);
        }
        return ans;
    }
};