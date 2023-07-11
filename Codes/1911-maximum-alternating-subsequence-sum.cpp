/*
 * @Author: LetMeFly
 * @Date: 2023-07-11 08:22:08
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-07-11 08:24:37
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif


typedef long long ll;

class Solution {
public:
    ll maxAlternatingSum(vector<int>& nums) {
        ll even = nums[0], old = 0;
        for (int i = 1; i < nums.size(); i++) {
            even = max(even, old + nums[i]);
            old = max(old, even - nums[i]);
        }
        return even;
    }
};