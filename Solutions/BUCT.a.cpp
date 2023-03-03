/*
 * @Author: LetMeFly
 * @Date: 2023-02-21 21:25:49
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-03-03 16:14:51
 */
#include <bits/stdc++.h>
using namespace std;
#define mem(a) memset(a, 0, sizeof(a))
#define dbg(x) cout << #x << " = " << x << endl
#define fi(i, l, r) for (int i = l; i < r; i++)
#define cd(a) scanf("%d", &a)
typedef long long ll;

struct Edge {
    int u, v, w;

    Edge(int u, int v, int w) : u(u), v(v), w(w) {}

    friend bool operator < (const Edge& a, const Edge& b) {
        return a.w > b.w;  // 权重小的优先
    }
};

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        vector<bool> visited(n + 1, false);
        vector<vector<Edge>> graph(n + 1);
        for (int i = 0; i < m; i++) {
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            Edge newEdge(u, v, w);
            graph[u].push_back(newEdge);
            graph[v].push_back(newEdge);
        }
        visited[1] = true;
        priority_queue<Edge> pq;
        for (Edge& thisEdge : graph[1]) {
            pq.push(thisEdge);
        }
        int ans = 0;
        int cntEdge = 0;
        while (cntEdge < n - 1) {
            Edge thisEdge = pq.top();  // 未考虑非连通图的情况，连通图下此时pq不会为空
            pq.pop();
            if (!visited[thisEdge.u] || !visited[thisEdge.v]) {
                ans += thisEdge.w;
                cntEdge++;
                visited[thisEdge.u] = visited[thisEdge.v] = true;
            }
        }
        cout << ans << endl;
    }
    return 0;
}