/*
 * @Author: LetMeFly
 * @Date: 2024-03-06 09:46:34
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-03-06 09:47:43
 * @Description: nums[i] < 2^31不是≤，因此i = 0到i < 31即可
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int findKOr(vector<int>& nums, int k) {
        int ans = 0;
        for (int i = 0; i < 32; i++) {
            int cnt = 0;
            for (int t : nums) {
                cnt += ((t >> i) & 1);
            }
            if (cnt >= k) {
                ans |= (1 << i);
            }
        }
        return ans;
    }
};