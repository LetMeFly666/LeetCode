/*
 * @Author: LetMeFly
 * @Date: 2023-10-12 18:37:05
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-10-12 18:39:33
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    long long findTheArrayConcVal(vector<int>& nums) {
        long long ans = 0;
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int t = nums[r];
            long long mul = 1;
            while (t) {
                t /= 10;
                mul *= 10;
            }
            ans += nums[l] * mul + nums[r];
            l++, r--;
        }
        if (l == r) {
            ans += nums[l];
        }
        return ans;
    }
};