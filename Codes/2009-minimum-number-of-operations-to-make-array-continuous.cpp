/*
 * @Author: LetMeFly
 * @Date: 2024-04-08 12:02:26
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-04-08 12:09:26
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int minOperations(vector<int>& originalNums) {
        int n = originalNums.size();
        unordered_set<int> differentNums(originalNums.begin(), originalNums.end());
        vector<int> nums(differentNums.begin(), differentNums.end());
        sort(nums.begin(), nums.end());
        int ans = n - 1;
        int r = 0;
        for (int l = 0; l < nums.size(); l++) {
            while (r < nums.size() && nums[r] <= nums[l] + n - 1) {
                r++;
            }
            ans = min(ans, n - (r - l));
        }
        return ans;
    }
};