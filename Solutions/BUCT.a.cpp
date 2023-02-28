/*
 * @Author: LetMeFly
 * @Date: 2023-02-21 21:25:49
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-02-27 21:54:04
 */
#include <bits/stdc++.h>
using namespace std;
#define mem(a) memset(a, 0, sizeof(a))
#define dbg(x) cout << #x << " = " << x << endl
#define fi(i, l, r) for (int i = l; i < r; i++)
#define cd(a) scanf("%d", &a)
typedef long long ll;
typedef pair<int, int> pii;
#define INF 1e9

int shortest[111];
vector<pii> graph[111];
bool visited[111];

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        // init
        for (int i = 1; i <= n; i++) {
            shortest[i] = INF;
            visited[i] = false;
            for (int j = 1; j <= n; j++) {
                graph[i].clear();
            }
        }
        // cin
        for (int i = 0; i < m; i++) {
            int u, v, d;
            scanf("%d%d%d", &u, &v, &d);
            graph[u].push_back({v, d});
        }
        int start;
        cin >> start;
        // begin
        shortest[start] = 0;
        for (int i = 0; i < n; i++) {  // 第一次求出start到start的最短距离
            int thisMinDistance = INF;
            int shortestPoint = -1;
            for (int j = 1; j <= n; j++) {
                if (!visited[j] && shortest[j] < thisMinDistance) {
                    thisMinDistance = shortest[j];
                    shortestPoint = j;
                }
            }
            if (shortestPoint == -1) {  // 节点可达
                break;
            }
            visited[shortestPoint] = true;
            for (auto[toPoint, distance] : graph[shortestPoint]) {
                shortest[toPoint] = min(shortest[toPoint], shortest[shortestPoint] + distance);
            }
        }
        for (int i = 1; i <= n; i++) {
            if (shortest[i] == INF) {
                printf("impossible ");
            }
            else {
                printf("%d ", shortest[i]);
            }
        }
    }
    return 0;
}
