/*
 * @Author: LetMeFly
 * @Date: 2023-02-21 21:25:49
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-03-03 16:50:44
 */
#include <bits/stdc++.h>
using namespace std;
#define mem(a) memset(a, 0, sizeof(a))
#define dbg(x) cout << #x << " = " << x << endl
#define fi(i, l, r) for (int i = l; i < r; i++)
#define cd(a) scanf("%d", &a)
typedef long long ll;

struct Edge {
    int toNode;
    int weight;

    Edge(int toNode, int weight) : toNode(toNode), weight(weight) {}

    friend bool operator < (const Edge& a, const Edge& b) {
        return a.weight > b.weight;  // 权重小的在前
    }
};

int main() {
    // freopen("C:/Users/LetMe/Desktop/test1.in", "r", stdin);
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
            graph[u].push_back({v, w});
            graph[v].push_back({u, w});
        }
        visited[1] = true;
        priority_queue<Edge> pq;
        for (Edge& thisEdge : graph[1]) {
            pq.push(thisEdge);
        }
        int ans = 0;
        int cntEdge = 0;
        while (cntEdge < n - 1) {
            if (!pq.size()) {
                break;
            }
            Edge thisEdge = pq.top();
            pq.pop();
            // printf("pq.size() = %lld\n", pq.size());  //*********
            if (!visited[thisEdge.toNode]) {
                visited[thisEdge.toNode] = true;
                ans += thisEdge.weight;
                cntEdge++;
                for (Edge& thatEdge : graph[thisEdge.toNode]) {
                    pq.push(thatEdge);
                }
            }
        }
        // printf("n = %d, cntEdge = %d, ans = ",n, cntEdge);  //*********
        if (cntEdge != n - 1) {
            puts("0");
        }
        else {
            cout << ans << endl;
        }
    }
    return 0;
}

/*
451
86
366
84
141
0
150
47

*/