/*
 * @Author: LetMeFly
 * @Date: 2023-07-25 06:22:20
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-07-25 06:24:37
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int halveArray(vector<int>& nums) {
        priority_queue<double> pq;
        double s = 0;
        for (int t : nums) {
            pq.push(t);
            s += t;
        }
        double need = s / 2;
        int ans = 0;
        while (need > 0) {
            double thisValue = pq.top();
            pq.pop();
            thisValue /= 2;
            need -= thisValue;
            pq.push(thisValue);
            ans++;
        }
        return ans;
    }
};