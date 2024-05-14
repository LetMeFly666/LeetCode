/*
 * @Author: LetMeFly
 * @Date: 2024-05-14 11:48:18
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-05-14 11:50:48
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int, int> ma;
        for (int t : tasks) {
            ma[t]++;
        }
        int ans = 0;
        for (auto& [val, times] : ma) {
            if (times == 1) {
                return -1;
            }
            ans += (times + 2) / 3;
        }
        return ans;
    }
};