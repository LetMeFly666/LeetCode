/*
 * @Author: LetMeFly
 * @Date: 2025-07-28 19:30:16
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-07-28 19:42:03
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    int ans = 0;
    int maxium = 0;
    vector<int> nums;

    void dfs(int th, int now) {
        if (th == nums.size()) {
            return;
        }
        if (now == maxium) {
            ans++;
        }
        dfs(th + 1, now);
        dfs(th + 1, now | nums[th]);
    }
public:
    int countMaxOrSubsets(vector<int>& nums) {
        for (int t : nums) {
            maxium |= t;
        }
        this->nums = move(nums);
        dfs(0, 0);
        return ans;
    }
};