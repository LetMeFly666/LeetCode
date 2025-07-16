/*
 * @Author: LetMeFly
 * @Date: 2025-07-16 13:16:29
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-07-16 13:19:44
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int ans = 0;
        int odd = 0;
        bool last = nums[0] % 2 ? false : true;
        for (int t : nums) {
            if (t % 2) {
                odd++;
                if (!last) {
                    last = true;
                    ans++;
                }
            } else {
                if (last) {
                    last = false;
                    ans++;
                }
            }
        }
        return max(ans, max(odd, int(nums.size()) - odd));
    }
};