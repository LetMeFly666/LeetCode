/*
 * @Author: LetMeFly
 * @Date: 2025-04-19 15:51:42
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-04-19 16:12:44
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

/*
l: first j 满足 nums[j] + nums[i] >= lower | nums[j] >= lower - nums[i]
r: last  j 满足 nums[j] + nums[i] <= upper | nums[j] <= upper - nums[i]

l: lower_bound(lower - nums[i])
r: upper_bound(upper - nums[i])
*/
typedef long long ll;
class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        ll ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            ans += upper_bound(nums.begin() + i + 1, nums.end(), upper - nums[i]) - lower_bound(nums.begin() + i + 1, nums.end(), lower - nums[i]);
            // cout << i << ": " << i << "[" << lower_bound(nums.begin() + i + 1, nums.end(), lower - nums[i]) - nums.begin() << ", " << upper_bound(nums.begin() + i + 1, nums.end(), upper - nums[i]) - nums.begin() << ')' << endl;
        }
        return ans;
    }
};