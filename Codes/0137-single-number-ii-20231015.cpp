/*
 * @Author: LetMeFly
 * @Date: 2023-10-15 15:29:08
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-10-15 19:11:51
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int cnt[32] = {0};
        for (int t : nums) {
            for (int i = 0; i < 32; i++) {
                cnt[i] += ((t >> i) & 1);
            }
        }
        int ans = 0;
        for (int i = 0; i < 32; i++) {
            ans |= (cnt[i] % 3) * (1 << i);
        }
        return ans;
    }
};