/*
 * @Author: LetMeFly
 * @Date: 2024-04-20 10:51:37
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-04-20 11:00:15
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    vector<vector<int>> ans;
    vector<int> now;

    void dfs(vector<int>& candidates, int target, int index) {
        if (!target) {
            ans.push_back(now);
            return;
        }
        if (index == candidates.size()) {
            return;
        }
        // not choose
        dfs(candidates, target, index + 1);
        // choose
        if (target - candidates[index] >= 0) {
            now.push_back(candidates[index]);
            dfs(candidates, target - candidates[index], index);  // 这里不能是index + 1，因为可以重复选择
            now.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        dfs(candidates, target, 0);
        return ans;
    }
};