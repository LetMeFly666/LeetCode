/*
 * @Author: LetMeFly
 * @Date: 2025-04-18 10:23:46
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-04-18 10:25:58
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

typedef long long ll;

class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        unordered_map<int, int> times;
        ll ans = nums.size() * (nums.size() - 1) / 2;
        for (int i = 0; i < nums.size(); i++) {
            ans -= times[nums[i] - i]++;
        }
        return ans;
    }
};