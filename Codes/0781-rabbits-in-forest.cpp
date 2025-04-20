/*
 * @Author: LetMeFly
 * @Date: 2025-04-20 19:35:57
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-04-20 19:40:16
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int> times;
        for (int t : answers) {
            times[t]++;
        }
        int ans = 0;
        for (auto [group, total] : times) {
            ans += (total + group) / (group + 1) * (group + 1);
        }
        return ans;
    }
};