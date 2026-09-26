/*
 * @Author: LetMeFly
 * @Date: 2026-07-18 07:00:55
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-07-18 07:23:34
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    int gcd1979(int a, int b) {
        if (a > b) {
            swap(a, b);
        }
        while (b) {
            // (a, b) = (b, a % b);
            int tmp = b;
            b = a % b;
            a = tmp;
        }
        return a;
    }
public:
    int findGCD(vector<int>& nums) {
        int m = nums[0], M = m;
        for (int t : nums) {
            m = min(m, t);
            M = max(M, t);
        }
        return gcd1979(m, M);
    }
};
