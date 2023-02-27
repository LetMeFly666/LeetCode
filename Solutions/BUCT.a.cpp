/*
 * @Author: LetMeFly
 * @Date: 2023-02-21 21:25:49
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-02-24 21:57:56
 */
#include <bits/stdc++.h>
using namespace std;
#define mem(a) memset(a, 0, sizeof(a))
#define dbg(x) cout << #x << " = " << x << endl
#define fi(i, l, r) for (int i = l; i < r; i++)
#define cd(a) scanf("%d", &a)
typedef long long ll;
typedef pair<int, int> pii;

int ans[111];
vector<pii> graph[111];
bool visited[111];

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        for (int i = 1; i <= n; i++) {
            ans[i] = 1e9;
            visited[i] = false;
            graph[i].clear();
        }
        while (m--) {
            int a, b, l;
            scanf("%d%d%d", &a, &b, &l);
            graph[a].push_back({b, l});
            // graph[b].push_back({a, l});
        }
        int start;
        cin >> start;
        queue<int> q;
        q.push(start);
        visited[start] = true;
        ans[start] = 0;
        while (q.size()) {
            int loc = q.front();
            q.pop();
            for (pii& edge : graph[loc]) {
                int toLoc = edge.first;
                int distance = edge.second;
                if (!visited[toLoc]) {
                    visited[toLoc] = true;
                    q.push(toLoc);
                }
                if (toLoc == 2 && ans[toLoc] > ans[loc] + distance) {  //**********
                    printf("ans[%d] + %d = %d\n", loc, distance, ans[loc] + distance);
                }
                ans[toLoc] = min(ans[toLoc], ans[loc] + distance);
            }
        }
        for (int i = 1; i <= n; i++) {
            if (ans[i] > 1e8) {
                printf("impossible ");
            }
            else {
                printf("%d ", ans[i]);
            }
        }
        puts("");
    }
    return 0;
}

// ans[11] + 15 = 27


/*
1 22 18 9 9 41 8 20 21 16 12 13 27 15 83 18 24 6 19 34 30 80 0 74 22 40

*/