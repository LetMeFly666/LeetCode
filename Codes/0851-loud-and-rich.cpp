/*
 * @Author: LetMeFly
 * @Date: 2021-12-15 18:37:39
 * @LastEditors: LetMeFly
 * @LastEditTime: 2021-12-15 18:40:33
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>> &richer, vector<int> &quiet) {
        int n = quiet.size();
        vector<vector<int>> g(n);
        vector<int> inDeg(n);
        for (auto &r : richer) {
            g[r[0]].emplace_back(r[1]);
            ++inDeg[r[1]];
        }

        vector<int> ans(n);
        iota(ans.begin(), ans.end(), 0);
        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (inDeg[i] == 0) {
                q.emplace(i);
            }
        }
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            for (int y : g[x]) {
                if (quiet[ans[x]] < quiet[ans[y]]) {
                    ans[y] = ans[x]; // 更新 x 的邻居的答案
                }
                if (--inDeg[y] == 0) {
                    q.emplace(y);
                }
            }
        }
        return ans;
    }
};

// 作者：LeetCode-Solution
// 链接：https://leetcode-cn.com/problems/loud-and-rich/solution/xuan-nao-he-fu-you-by-leetcode-solution-jnzm/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。