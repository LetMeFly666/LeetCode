/*
 * @Author: LetMeFly
 * @Date: 2022-04-14 12:26:37
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-04-14 12:27:55
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int ans = 0;
        for (auto& thisV : accounts) {
            int thisAns = 0;
            for (auto& t : thisV) {
                thisAns += t;
            }
            ans = max(ans, thisAns);
        }
        return ans;
    }
};