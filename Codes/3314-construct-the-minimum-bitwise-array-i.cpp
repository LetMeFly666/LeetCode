/*
 * @Author: LetMeFly
 * @Date: 2026-01-20 22:50:06
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-01-20 22:52:17
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    int get(int n) {
        for (int i = 0; i <= n; i++) {
            if ((i | (i + 1)) == n) {
                return i;
            }
        }
        return -1;
    }
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            ans[i] = get(nums[i]);
        }
        return ans;
    }
};