/*
 * @Author: LetMeFly
 * @Date: 2025-02-05 12:25:14
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-02-05 12:28:24
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    vector<vector<int>> ans;
    vector<int> now;

    void dfs(vector<int>& a, int loc) {
        if (loc == a.size()) {
            ans.push_back(now);
            return;
        }
        // 选当前
        now.push_back(a[loc]);
        dfs(a, loc + 1);
        now.pop_back();
        // 不选当前
        int next = loc + 1;
        while (next < a.size() && a[loc] == a[next]) {
            next++;
        }
        dfs(a, next);
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        dfs(nums, 0);
        return ans;
    }
};