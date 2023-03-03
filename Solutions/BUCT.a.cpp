/*
 * @Author: LetMeFly
 * @Date: 2023-02-21 21:25:49
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-03-02 22:00:45
 */
#include <bits/stdc++.h>
using namespace std;
#define mem(a) memset(a, 0, sizeof(a))
#define dbg(x) cout << #x << " = " << x << endl
#define fi(i, l, r) for (int i = l; i < r; i++)
#define cd(a) scanf("%d", &a)
typedef long long ll;

struct Node {
    int u, v, w;
} a[10010];

bool cmp(const Node& a, const Node& b) {
    return a.w < b.w;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < m; i++) {
            scanf("%d%d%d", &a[i].u, &a[i].v, &a[i].w);
        }
        sort(a, a + m, cmp);
        vector<bool> visited(n + 1);
        int cntNode = 0;
        int ans = 0;
        for (int i = 0; i < m; i++) {
            bool use = false;
            if (!visited[a[i].u]) {
                visited[a[i].u] = true;
                cntNode += 1;
                use = true;
            }
            if (!visited[a[i].v]) {
                visited[a[i].v] = true;
                cntNode += 1;
                use = true;
            }
            if (use) {
                ans += a[i].w;
            }
            if (cntNode == n) {
                break;
            }
        }
        cout << ans << endl;
    }
    return 0;
}