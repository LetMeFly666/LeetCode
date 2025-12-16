/*
 * @Author: LetMeFly
 * @Date: 2025-12-16 18:37:53
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-12-16 19:00:52
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