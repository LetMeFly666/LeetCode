/*
 * @Author: LetMeFly
 * @Date: 2023-10-21 15:19:43
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-10-21 15:29:18
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

typedef long long ll;
class Solution {
public:
    ll countPairs(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        for (auto& v : edges) {
            graph[v[0]].push_back(v[1]);
            graph[v[1]].push_back(v[0]);
        }
        vector<ll> sizes;
        vector<bool> visited(n);
        ll mul = 1;
        for (int i = 0; i < n; i++) {
            if (visited[i]) {
                continue;
            }
            int cntNode = 0;
            visited[i] = true;
            queue<int> q;
            q.push(i);
            while (q.size()) {
                int thisNode = q.front();
                cntNode++;
                q.pop();
                for (int t : graph[thisNode]) {
                    if (!visited[t]) {
                        visited[t] = true;
                        q.push(t);
                    }
                }
            }
            sizes.push_back(cntNode);
            mul *= cntNode;
        }
        if (sizes.size() == 1) {  // 注意！
            return 0;
        }
        ll ans = 0;
        for (ll t : sizes) {
            ans += mul / t;
        }
        return ans;
    }
};