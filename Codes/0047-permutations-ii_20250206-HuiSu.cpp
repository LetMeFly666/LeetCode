/*
 * @Author: LetMeFly
 * @Date: 2025-02-06 13:57:12
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-02-06 14:03:17
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    void dfs(int n, vector<vector<int>>& ans, vector<int>& now, vector<bool>& visited, vector<int>& nums) {
        if (n == nums.size()) {
            ans.push_back(now);
        }
        for (int i = 0; i < nums.size(); i++) {
            if (visited[i] || i && nums[i] == nums[i - 1] && !visited[i - 1]) {
                continue;
            }
            now.push_back(nums[i]);
            visited[i] = true;
            dfs(n + 1, ans, now, visited, nums);
            visited[i] = false;
            now.pop_back();
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> now;
        vector<bool> visited(nums.size());
        sort(nums.begin(), nums.end());
        dfs(0, ans, now, visited, nums);
        return ans;
    }
};