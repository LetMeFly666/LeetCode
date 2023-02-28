/*
 * @Author: LetMeFly
 * @Date: 2023-02-21 21:25:49
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-02-28 12:26:03
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

int shortestDistance[111];
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
            shortestDistance[i] = INF;
            visited[i] = false;
            graph[i].clear();
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
        shortestDistance[start] = 0;
        for (int i = 0; i < n; i++) {
            int thisMinDistance = INF;
            int shortestNode = -1;
            for (int j = 1; j <= n; j++) {
                if (!visited[j] && shortestDistance[j] < thisMinDistance) {
                    thisMinDistance = shortestDistance[j];
                    shortestNode = j;
                }
            }
            if (shortestNode == -1) {
                break;
            }
            visited[shortestNode] = true;
            for (auto& [nodeTo, thisDistance] : graph[shortestNode]) {
                shortestDistance[nodeTo] = min(shortestDistance[nodeTo], shortestDistance[shortestNode] + thisDistance);
            }
        }
        // cout
        for (int i = 1; i <= n; i++) {
            if (shortestDistance[i] == INF) {
                printf("impossible ");
            }
            else {
                printf("%d ", shortestDistance[i]);
            }
        }
        puts("");
    }    
    return 0;
}