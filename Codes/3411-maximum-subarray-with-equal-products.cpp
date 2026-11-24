/*
 * @Author: LetMeFly
 * @Date: 2026-11-24 13:04:33
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-11-24 18:28:15
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int maxLength(vector<int>& nums) {
        size_t n = nums.size();
        int mx = nums[0], all_lcm = nums[0];
        for (size_t i = 1; i < n; i++) {
            mx = max(mx, nums[i]);
            all_lcm = lcm(all_lcm, nums[i]);
        }
        int up_to = mx * all_lcm;
        
        size_t ans = 1;
        for (size_t i = 0; i < n; i++) {
            int prod = nums[i], this_gcd = nums[i], this_lcm = nums[i];
            for (size_t j = i + 1; j < n; j++) {
                prod *= nums[j];
                if (prod > up_to) {
                    break;
                }
                this_gcd = gcd(this_gcd, nums[j]);
                this_lcm = lcm(this_lcm, nums[j]);
                if (prod == this_gcd * this_lcm) {
                    ans = max(ans, j - i + 1);
                }
            }
        }
        return static_cast<int>(ans);
    }
};
