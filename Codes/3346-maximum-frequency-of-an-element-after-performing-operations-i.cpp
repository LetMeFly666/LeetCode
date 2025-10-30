/*
 * @Author: LetMeFly
 * @Date: 2025-10-21 18:51:21
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-10-30 22:51:38
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        sort(nums.begin(), nums.end());
        unordered_map<int, int> frequency;
        for (int t : nums) {
            frequency[t]++;
        }
        int ans = 0;
        for (int l = 0, r = 0, i = 0; i < nums.size(); i++) {
            while (nums[i] - nums[l] > k) {
                l++;
            }
            while (r < nums.size() && nums[r] - nums[i] <= k) {
                r++;
            }
            ans = max(ans, min(r - l, numOperations + frequency[nums[i]]));
        }
        return ans;
    }
};