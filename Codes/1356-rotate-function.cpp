/*
 * @Author: LetMeFly
 * @Date: 2022-04-22 08:30:24
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-04-22 08:35:09
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int ans = 0;
        int s = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            ans += i * nums[i];
            s += nums[i];
        }
        int nowAns = ans;
        for (int i = n - 1; i > 0; i--) {
            nowAns = nowAns - (n - 1) * nums[i] + (s - nums[i]);
            ans = max(ans, nowAns);
        }
        return ans;
    }
};