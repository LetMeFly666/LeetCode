/*
 * @Author: LetMeFly
 * @Date: 2023-11-20 10:27:36
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-11-20 10:37:45
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = nums[0];
        int cnt = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            cnt = max(cnt + nums[i], nums[i]);
            ans = max(ans, cnt);
        }
        return ans;
    }
};