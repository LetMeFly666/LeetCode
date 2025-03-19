/*
 * @Author: LetMeFly
 * @Date: 2025-03-19 23:16:07
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-19 23:17:17
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> se(nums.begin(), nums.end());
        int ans = 0;
        for (int t : se) {
            if (se.count(t - 1)) {
                continue;
            }
            int cnt = 1;
            while (se.count(++t)) {
                cnt++;
            }
            ans = max(ans, cnt);
        }
        return ans;
    }
};