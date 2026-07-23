/*
 * @Author: LetMeFly
 * @Date: 2026-07-23 14:50:11
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-07-23 14:55:02
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) {
            return n;
        }
        
        int cnt = 0;
        while (n) {
            n >>= 1;
            cnt++;
        }
        return 1 << cnt;
    }
};
