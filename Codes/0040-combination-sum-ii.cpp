/*
 * @Author: LetMeFly
 * @Date: 2025-01-26 07:27:24
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-01-26 07:57:37
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    vector<vector<int>> ans;
    vector<int> now;

    void dfs(vector<int>& c, int target, int index) {
        // 组合成功
        if (!target) {
            ans.push_back(now);
            return;
        }
        // 不再可能
        if (index == c.size() || target < 0) {
            return;
        }
        // 选当前
        now.push_back(c[index]);
        dfs(c, target - c[index], index + 1);
        now.pop_back();
        // 不选当前递归下一个
        int next = index;
        while (++next < c.size() && c[next] == c[index]);
        dfs(c, target, next);
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        dfs(candidates, target, 0);
        return ans;
    }
};

#ifdef _WIN32
/*
[1,1,2,5,6,7,10]
8

[[1,1,6],[1,2,5],[1,7],[2,6]]
*/
/*
[2,5,2,1,2]
5

[[1,2,2],[5]]
*/
int main() {
    string s;
    int t;
    Solution sol;
    while (cin >> s >> t) {
        vector<int> v = stringToVector(s);
        debug(sol.combinationSum2(v, t));
    }
    return 0;
}
#endif