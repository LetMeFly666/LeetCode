/*
 * @Author: LetMeFly
 * @Date: 2023-10-28 09:27:03
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-10-28 09:33:33
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

typedef long long ll;

class Solution {
public:
    ll pickGifts(vector<int>& gifts, int k) {
        ll cnt = 0;
        for (int t : gifts) {
            cnt += t;
        }
        priority_queue<ll> pq(gifts.begin(), gifts.end());
        while (k--) {
            ll thisGift = pq.top();
            pq.pop();
            cnt -= thisGift - sqrt(thisGift);
            pq.push(sqrt(thisGift));
        }
        return cnt;
    }
};