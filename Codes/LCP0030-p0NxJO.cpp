/*
 * @Author: LetMeFly
 * @Date: 2024-02-06 10:30:51
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-02-06 10:33:07
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int magicTower(vector<int>& nums) {
        priority_queue<int> pq;
        int now = 1;
        int totalNegative = 0;
        int ans = 0;
        for (int t : nums) {
            if (t < 0) {
                pq.push(-t);
            }
            now += t;
            while (now <= 0 && pq.size()) {
                int thisNegative = pq.top();
                pq.pop();
                now += thisNegative;
                totalNegative += thisNegative;
                ans++;
            }
            if (now <= 0) {
                return -1;
            }
        }
        return now > totalNegative ? ans : -1;
    }
};