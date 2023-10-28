/*
 * @Author: LetMeFly
 * @Date: 2023-10-28 09:27:03
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-10-28 09:50:14
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

#ifdef FirstTry  // 额外的堆（优先队列）
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

#else  // FirstTry
// SecondTry
class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        make_heap(gifts.begin(), gifts.end());
        while (k--) {
            pop_heap(gifts.begin(), gifts.end());  // 弹出堆顶并一到数组末尾
            gifts.back() = sqrt(gifts.back());
            push_heap(gifts.begin(), gifts.end());
        }
        return accumulate(gifts.begin(), gifts.end(), 0LL);
    }
};
#endif  // FirstTry