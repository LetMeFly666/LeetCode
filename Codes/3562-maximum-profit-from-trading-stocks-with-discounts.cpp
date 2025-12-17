/*
 * @Author: LetMeFly
 * @Date: 2025-12-16 18:37:53
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-12-17 13:42:11
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#include <iostream>
#endif

class Solution {
private:
    unordered_map<int, vector<int>> tree;
    vector<int> present;
    vector<int> future;
    vector<vector<int>> dfs(int node, int budget) {
        /*
            return f:
                f[i][j]: node及其所有子节点共花费i的最大总收益
                         j=0：node没半价 / j=1：node半价买
        */

        // 先算subF
        vector<vector<int>> subF(2, vector<int>(budget + 1));
        for (int child : tree[node]) {
            vector<vector<int>> thisF = dfs(child, budget);
            for (int j = 0; j < 2; j++) {
                for (int i = budget; i >= 0; i--) {
                    for (int first = min(budget, i); first >= 0; first--) {
                        subF[j][i] = max(subF[j][i], subF[j][first] + thisF[j][i - first]);
                    }
                }
            }
        }

        // 再算当前节点
        vector<vector<int>> f(2, vector<int>(budget + 1));
        for (int j = 0; j < 2; j++) {
            for (int i = 0; i <= budget; i++) {
                int cost = present[node - 1] / (j + 1);
                if (i > cost) {
                    f[j][i] = max(subF[0][i], subF[1][i - cost] + future[node - 1] - cost);
                } else {
                    f[j][i] = subF[0][i];
                }
            }
        }

        return f;
    }
public:
    int maxProfit(int n, vector<int>& present, vector<int>& future, vector<vector<int>>& hierarchy, int budget) {
        for (vector<int>& h : hierarchy) {
            tree[h[0]].push_back(h[1]);
        }
        this->present = move(present);
        this->future = move(future);
        vector<vector<int>> f = dfs(1, budget);
        return *max_element(f[0].begin(), f[0].end());
    }
};

#if defined(_WIN32) || defined(__APPLE__)
/*
3 [6,4,23] [50,48,17] [[1,3],[1,2]] 28

96

1买: 赚44，剩22
2买: 赚
*/
int main() {
    int n, budget;
    string a, b, c;
    while (cin >> n >> a >> b >> c >> budget) {
        vector<int> present = stringToVector(a);
        vector<int> future = stringToVector(b);
        vector<vector<int>> hierarchy = stringToVectorVector(c);
        Solution sol;
        cout << sol.maxProfit(n, present, future, hierarchy, budget) << endl;
    }
    return 0;
}
#endif