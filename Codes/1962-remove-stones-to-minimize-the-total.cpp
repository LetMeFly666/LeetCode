/*
 * @Author: LetMeFly
 * @Date: 2023-12-23 09:31:54
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-12-23 09:38:56
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        int ans = accumulate(piles.begin(), piles.end(), 0);
        priority_queue<int> pq(piles.begin(), piles.end());
        while (k--) {
            int t = pq.top();
            pq.pop();
            pq.push((t + 1) / 2);
            ans -= t / 2;
        }
        return ans;
    }
};