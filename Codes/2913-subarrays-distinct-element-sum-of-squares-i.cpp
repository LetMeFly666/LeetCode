/*
 * @Author: LetMeFly
 * @Date: 2026-10-15 22:18:00
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-10-15 22:19:33
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int ans = 0;
        for (int i = 0, n = nums.size(); i < n; i++) {
            unordered_set<int> se;
            for (int j = 0; j <= i; j++) {
                se.insert(nums[j]);
                ans += se.size() * se.size();
            }
        }
        return ans;
    }
};
