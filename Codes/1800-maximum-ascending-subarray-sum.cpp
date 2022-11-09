/*
 * @Author: LetMeFly
 * @Date: 2022-10-07 13:43:57
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-10-07 13:45:48
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int ans = 0;
        int nowCnt = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] <= nums[i - 1]) {
                ans = max(ans, nowCnt);
                nowCnt = 0;
            }
            nowCnt += nums[i];
        }
        ans = max(ans, nowCnt);
        return ans;
    }
};