/*
 * @Author: LetMeFly
 * @Date: 2024-04-21 13:48:33
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-04-21 14:15:38
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    vector<vector<int>> ans;
    vector<int> now;

    // 从[index,9]范围内选k个数使得和为n
    void dfs(int k, int n, int index) {
        if (!k && !n) {
            ans.push_back(now);
            return;
        }
        if (index > n || index == 10 || k <= 0) {
            return;
        }
        // not choose
        dfs(k, n, index + 1);
        // choose
        now.push_back(index);
        dfs(k - 1, n - index, index + 1);
        now.pop_back();
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        dfs(k, n, 1);
        return ans;
    }
};