/*
 * @Author: LetMeFly
 * @Date: 2025-10-16 19:40:17
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-10-16 20:23:38
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

// THIS IS RIGHT
class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        unordered_map<int, int> ma;
        for (int t : nums) {
            ma[(t % value + value) % value]++;
        }
        int ans = 0;
        while (true) {
            if (--ma[ans % value] == -1) {
                return ans;
            }
            ans++;
        }
    }
};