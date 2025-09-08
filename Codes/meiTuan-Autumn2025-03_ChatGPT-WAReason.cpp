/*
 * @Author: LetMeFly
 * @Date: 2025-09-06 10:57:34
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-09-06 11:21:01
 */

/*
n个节点n-1条边组成的无向树，给节点为1，每个节点有一个值a[i]。
对于节点u定义其权值为：
 - 若u为叶，权值为a[i]
 - 否则，权值为所有子节点值分别异或的最大值，max(a[u] ^ a[i1], a[u] ^ a[i2], ...)
接下来对这棵树进行m次操作，每次操作有以下三种类型：
 - 1 u x：将节点u的值改为x
 - 2 x y：查询编号在[x, y]区间内节点的最大权值
 - 3 u：查询节点u所有节点的最大权值
输入：
n m
a1, a2, ...
u1 v1
u2 v2
...
操作1
操作2
...
数据范围：
1 <= n, m <= 3 * 10^5
1 <= a[i] <= 10^9
*/

/*
# ========== Case 1: 最小规模 (n=1) ==========
1 5
7
3 1
2 1 1
1 1 10
3 1
2 1 1

# ========== Case 2: 链状树 (n=4) ==========
4 7
1 2 3 4
1 2
2 3
3 4
3 4
2 1 4
1 2 10
3 2
3 3
1 4 7
2 2 4

# ========== Case 3: 星型树 (n=5) ==========
5 8
5 1 2 3 4
1 2
1 3
1 4
1 5
3 1
3 2
1 3 7
3 1
2 1 5
1 1 9
3 1
2 2 5

# ========== Case 4: 普通树 (n=6) ==========
6 10
8 6 4 2 10 1
1 2
1 3
2 4
2 5
3 6
3 2
3 1
2 1 6
1 5 15
3 2
1 1 20
3 1
2 2 4
1 6 30
3 3
2 3 6

# ========== Case 5: 更大规模，复杂操作 (n=7) ==========
7 12
10 20 30 40 50 60 70
1 2
1 3
2 4
2 5
3 6
3 7
2 1 7
3 1
3 4
1 4 100
3 2
2 2 5
1 1 200
3 1
1 7 300
3 3
2 3 7
1 6 400
2 1 7

*/

// AI coding:
#include <bits/stdc++.h>
using namespace std;

const int MAXB = 29;

struct Trie {
    struct Node {
        int ch[2];
        int cnt;
        Node() { ch[0] = ch[1] = -1; cnt = 0; }
    };
    vector<Node> nodes;
    Trie() { nodes.reserve(32); nodes.push_back(Node()); }

    void clear() { nodes.clear(); nodes.push_back(Node()); }

    void insertVal(int x) {
        int p = 0;
        nodes[p].cnt++;
        for (int b = MAXB; b >= 0; --b) {
            int bit = (x >> b) & 1;
            if (nodes[p].ch[bit] == -1) {
                nodes[p].ch[bit] = (int)nodes.size();
                nodes.push_back(Node());
            }
            p = nodes[p].ch[bit];
            nodes[p].cnt++;
        }
    }

    void eraseVal(int x) {
        int p = 0;
        nodes[p].cnt--;
        for (int b = MAXB; b >= 0; --b) {
            int bit = (x >> b) & 1;
            int nx = nodes[p].ch[bit];
            
            p = nx;
            nodes[p].cnt--;
        }
    }

    int maxXor(int val) {
        if (nodes[0].cnt == 0) return 0;
        int p = 0;
        int res = 0;
        for (int b = MAXB; b >= 0; --b) {
            int bit = (val >> b) & 1;
            int opp = bit ^ 1;
            if (nodes[p].ch[opp] != -1 && nodes[nodes[p].ch[opp]].cnt > 0) {
                res |= (1 << b);
                p = nodes[p].ch[opp];
            } else {
                p = nodes[p].ch[bit];
            }
        }
        return res;
    }
};

struct SegTree {
    int n;
    vector<int> st;
    SegTree() {}
    SegTree(int _n) { init(_n); }
    void init(int _n) {
        n = _n;
        st.assign(4*n+5, 0);
    }
    void build(int p, int l, int r, const vector<int>& arr) {
        if (l == r) {
            st[p] = arr[l];
            return;
        }
        int m = (l + r) >> 1;
        build(p<<1, l, m, arr);
        build(p<<1|1, m+1, r, arr);
        st[p] = max(st[p<<1], st[p<<1|1]);
    }
    void pointUpdate(int p, int l, int r, int idx, int val) {
        if (l == r) { st[p] = val; return; }
        int m = (l + r) >> 1;
        if (idx <= m) pointUpdate(p<<1, l, m, idx, val);
        else pointUpdate(p<<1|1, m+1, r, idx, val);
        st[p] = max(st[p<<1], st[p<<1|1]);
    }
    int rangeMax(int p, int l, int r, int L, int R) {
        if (R < l || r < L) return INT_MIN;
        if (L <= l && r <= R) return st[p];
        int m = (l + r) >> 1;
        return max(rangeMax(p<<1, l, m, L, R), rangeMax(p<<1|1, m+1, r, L, R));
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    if (!(cin >> n >> m)) return 0;
    vector<int> a(n+1);
    for (int i = 1; i <= n; ++i) cin >> a[i];

    vector<vector<int>> adj(n+1);
    for (int i = 0; i < n-1; ++i) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> parent(n+1, 0);
    vector<vector<int>> children(n+1);
    vector<int> order; order.reserve(n);
    order.push_back(1);
    parent[1] = 0;
    for (int i = 0; i < (int)order.size(); ++i) {
        int u = order[i];
        for (int v: adj[u]) {
            if (v == parent[u]) continue;
            parent[v] = u;
            children[u].push_back(v);
            order.push_back(v);
        }
    }

    vector<Trie> tries(n+1);
    for (int u = 1; u <= n; ++u) {
        tries[u] = Trie();
    }

    for (int u = 1; u <= n; ++u) {
        for (int ch: children[u]) {
            tries[u].insertVal(a[ch]);
        }
    }

    vector<int> w(n+1, 0);
    for (int u = 1; u <= n; ++u) {
        if (children[u].empty()) w[u] = a[u];
        else w[u] = tries[u].maxXor(a[u]);
    }

    SegTree seg; seg.init(n);
    vector<int> arr(n+1);
    for (int i = 1; i <= n; ++i) arr[i] = w[i];
    seg.build(1, 1, n, arr);

    for (int qi = 0; qi < m; ++qi) {
        int type; cin >> type;
        if (type == 1) {
            int u, x; cin >> u >> x;
            int old = a[u];
            if (old == x) {
                a[u] = x;
                continue;
            }
            a[u] = x;

            
            if (children[u].empty()) {
                w[u] = a[u];
            } else {
                w[u] = tries[u].maxXor(a[u]);
            }
            seg.pointUpdate(1, 1, n, u, w[u]);

            
            int p = parent[u];
            if (p != 0) {
                
                tries[p].eraseVal(old);
                tries[p].insertVal(x);
                
                if (children[p].empty()) w[p] = a[p];
                else w[p] = tries[p].maxXor(a[p]);
                seg.pointUpdate(1, 1, n, p, w[p]);
            }

        } else if (type == 2) {
            int L, R; cin >> L >> R;
            int ans = seg.rangeMax(1, 1, n, L, R);
            cout << ans << '\n';
        } else if (type == 3) {
            int u; cin >> u;
            cout << w[u] << '\n';
        }
    }

    return 0;
}
