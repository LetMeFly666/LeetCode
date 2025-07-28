/*
 * @Author: LetMeFly
 * @Date: 2025-07-28 19:30:16
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-07-28 19:43:19
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    int maxium = 0;
    vector<int> nums;

    int dfs(int th, int now, int ans) {
        if (th == nums.size()) {
            return ans;
        }
        if (now == maxium) {
            ans++;  // 不能return，后面还有可选的呢
        }
        if (now | nums[th] == now) {
            return 2 * dfs(th + 1, now, ans);
        }
        return dfs(th + 1, now, ans) + dfs(th + 1, now | nums[th], ans);
    }
public:
    int countMaxOrSubsets(vector<int>& nums) {
        for (int t : nums) {
            maxium |= t;
        }
        this->nums = move(nums);
        return dfs(0, 0, 0);
    }
};