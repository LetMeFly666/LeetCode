/*
 * @Author: LetMeFly
 * @Date: 2026-05-10 19:40:18
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-05-10 21:31:58
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    int n, target;
    vector<int> nums, mem;

    int dfs(int loc) {
        if (loc == 0) {
            return 0;
        }
        int& ans = mem[loc];  // 引用
        if (ans) {
            return ans;
        }

        ans = INT_MIN;
        for (int i = 0; i < loc; i++) {
            if (abs(nums[loc] - nums[i]) <= target) {
                ans = max(ans, dfs(i) + 1);
            }
        }
        return ans;
    }
public:
    int maximumJumps(vector<int>& nums, int target) {
        n = nums.size();
        this->nums = move(nums);
        this->target = target;
        mem.assign(n, 0);
        int ans = dfs(n - 1);
        return ans < 0 ? -1 : ans;
    }
};
