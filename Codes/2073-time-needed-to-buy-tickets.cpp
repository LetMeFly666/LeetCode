/*
 * @Author: LetMeFly
 * @Date: 2024-09-30 00:05:29
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-09-30 00:07:10
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int ans = 0;
        for (int i = 0; i < tickets.size(); i++) {
            ans += i <= k ? min(tickets[i], tickets[k]) : min(tickets[i], tickets[k] - 1);
        }
        return ans;
    }
};