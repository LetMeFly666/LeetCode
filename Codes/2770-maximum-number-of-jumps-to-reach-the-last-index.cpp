/*
 * @Author: LetMeFly
 * @Date: 2026-05-10 19:40:18
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-05-10 19:46:10
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    int n, target;
    vector<int> nums;
    vector<int> mem;

    int dfs(int loc) {
        if (mem[loc] >= -1) {
            return mem[loc];
        }
        if (loc == 0) {
            return mem[loc] = 0;
        }

        int ans = n + 1;
        for (int i = 0; i < loc; i++) {
            if (abs(nums[loc] - nums[i] <= target)) {
                int val = dfs(i);
                if (val != -1) {
                    ans = min(ans, val + 1);
                }
            }
        }
        return mem[loc] = ans == n + 1 ? -1 : ans;
    }
public:
    int maximumJumps(vector<int>& nums, int target) {
        n = nums.size();
        this->nums = move(nums);
        this->target = target;
        mem = move(vector<int>(n, -2));
        return dfs(n - 1);
    }
};
