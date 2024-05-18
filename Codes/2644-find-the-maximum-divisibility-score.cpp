/*
 * @Author: LetMeFly
 * @Date: 2024-05-18 15:33:56
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-05-18 15:36:43
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int maxDivScore(vector<int>& nums, vector<int>& divisors) {
        int M = -1, ans = 0;
        for (int d : divisors) {
            int thisCnt = 0;
            for (int n : nums) {
                if (n % d == 0) {
                    thisCnt++;
                }
            }
            if (thisCnt > M) {
                M = thisCnt;
                ans = d;
            }
            else if (thisCnt == M) {
                M = thisCnt;
                ans = min(ans, d);
            }
        }
        return ans;
    }
};