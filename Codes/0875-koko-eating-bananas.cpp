/*
 * @Author: LetMeFly
 * @Date: 2022-06-07 08:22:29
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-06-07 08:31:08
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, r = 1e9;
        function<bool(int)> check = [&piles, &h](int k) {
            int s = 0;
            for (int& t : piles) {
                s += t / k + (t % k != 0);
            }
            return s <= h;
        };
        while (l < r) {
            int mid = (l + r) >> 1;
            if (check(mid)) {
                r = mid;
            }
            else {
                l = mid + 1;
            }
        }
        return r;
    }
};