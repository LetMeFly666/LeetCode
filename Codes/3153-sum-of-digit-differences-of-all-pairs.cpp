/*
 * @Author: LetMeFly
 * @Date: 2024-08-30 21:59:52
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-08-30 22:04:20
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

typedef long long ll;
class Solution {
public:
    ll sumDigitDifferences(vector<int>& nums) {
        ll ans = 0;
        do {
            ll times[10] = {0};
            for (int& t : nums) {
                times[t % 10]++;
                t /= 10;
            }
            for (int i = 0; i < 10; i++) {
                ans += times[i] * (nums.size() - times[i]);
            }
        } while (nums[0]);
        return ans / 2;
    }
};