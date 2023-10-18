/*
 * @Author: LetMeFly
 * @Date: 2023-10-18 09:12:11
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-10-18 09:38:39
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

typedef long long ll;
class Solution {
public:
    ll maxKelements(vector<int>& nums, int k) {
        priority_queue<int> pq(nums.begin(), nums.end());
        ll ans = 0;
        while (k--) {
            int thisNum = pq.top();
            pq.pop();
            ans += thisNum;
            pq.push((thisNum + 2) / 3);
        }
        return ans;
    }
};