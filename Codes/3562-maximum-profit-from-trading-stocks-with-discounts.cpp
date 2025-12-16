/*
 * @Author: LetMeFly
 * @Date: 2025-12-16 18:37:53
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-12-16 18:49:00
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    int ans = 0;
    vector<int> present, future;
    unordered_map<int, vector<int>> childs;

    void dfs(int node, bool fatherBought, int now, int budget) {
        int cost = present[node - 1];
        if (fatherBought) {
            cost /= 2;
        }
        int afterBuy = now + future[node - 1] - cost;
        if (cost <= budget) {
            ans = max(ans, afterBuy);
        }
        for (int child : childs[node]) {
            dfs(child, false, now, budget);
            if (cost <= budget) {
                dfs(child, true, afterBuy, budget - cost);
            }
        }
    }
public:
    int maxProfit(int n, vector<int>& present, vector<int>& future, vector<vector<int>>& hierarchy, int budget) {
        this->present = move(present);
        this->future = move(future);
        for (vector<int>& h : hierarchy) {
            childs[h[0]].push_back(h[1]);
        }
        dfs(1, false, 0, budget);
        return ans;
    }
};