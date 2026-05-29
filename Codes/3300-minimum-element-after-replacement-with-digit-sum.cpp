/*
 * @Author: LetMeFly
 * @Date: 2026-05-29 13:59:12
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-05-29 13:59:39
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int minElement(vector<int>& nums) {
        int ans = 36;
        for (int t : nums) {
            int s = 0;
            while (t) {
                s += t % 10;
                t /= 10;
            }
        }
        return ans;
    }
};
