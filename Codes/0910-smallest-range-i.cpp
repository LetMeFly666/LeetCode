/*
 * @Author: LetMeFly
 * @Date: 2024-10-21 22:53:20
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-10-21 23:01:28
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

/*
4 3 2
4 3 } 1
2 5 } 3
*/
class Solution {
public:
    int smallestRangeII(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int ans = nums.back() - nums[0];
        for (int i = 0; i < nums.size() - 1; i++) {  // nums[0..i]变大 nums[i+1..n-1]变小
            ans = min(ans, max(nums[i] + k, nums.back() - k) - min(nums[i + 1] - k, nums[0] + k));
        }
        return ans;
    }
};