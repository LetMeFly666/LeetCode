/*
 * @Author: LetMeFly
 * @Date: 2026-06-23 21:24:26
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-06-23 21:37:57
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

typedef long long ll;
const ll MOD = 1e9 + 7;
class Solution {
private:
    ll pow(ll a, ll b) {
        ll ans = 1;
        while (b) {
            if (b & 1) {
                ans = ans * a % MOD;
            }
            a = a * a % MOD;
            b >>= 1;
        }
        return ans;
    }
public:
    int assignEdgeWeights(vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> graph;
        for (vector<int>& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        unordered_map<int, int> depth;
        int max_depth = 1;
        depth[1] = 1;  // 不使用0是为了便于区分是否visited过
        queue<int> q;
        q.push(1);
        while (q.size()) {
            int last = q.front();
            q.pop();
            for (int next : graph[last]) {
                if (!depth.count(next)) {
                    depth[next] = depth[last] + 1;
                    q.push(next);
                    max_depth = max(max_depth, depth[next]);
                }
            }
        }
        max_depth--;

        return pow(max_depth - 1, 2);
    }
};
