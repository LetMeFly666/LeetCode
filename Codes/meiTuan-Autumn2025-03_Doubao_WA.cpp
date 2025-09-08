#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct TrieNode {
    int count;
    TrieNode* children[2];
    TrieNode() : count(0) {
        children[0] = children[1] = nullptr;
    }
};

class Trie {
private:
    TrieNode* root;

    void deleteNode(TrieNode* node) {
        if (!node) return;
        deleteNode(node->children[0]);
        deleteNode(node->children[1]);
        delete node;
    }

public:
    Trie() : root(new TrieNode()) {}
    ~Trie() { deleteNode(root); }

    void insert(int num) {
        TrieNode* node = root;
        for (int i = 30; i >= 0; --i) {
            int bit = (num >> i) & 1;
            if (!node->children[bit]) {
                node->children[bit] = new TrieNode();
            }
            node = node->children[bit];
            node->count++;
        }
    }

    void remove(int num) {
        TrieNode* node = root;
        for (int i = 30; i >= 0; --i) {
            int bit = (num >> i) & 1;
            if (!node->children[bit]) return;
            node = node->children[bit];
            node->count--;
        }
    }

    int queryMaxXOR(int num) {
        TrieNode* node = root;
        int maxXOR = 0;
        for (int i = 30; i >= 0; --i) {
            if (!node) break;
            int bit = (num >> i) & 1;
            int desiredBit = 1 - bit;
            if (node->children[desiredBit] && node->children[desiredBit]->count > 0) {
                maxXOR |= (1 << i);
                node = node->children[desiredBit];
            } else {
                node = node->children[bit];
            }
        }
        return maxXOR;
    }
};

class SegmentTree {
private:
    vector<int> tree;
    int n;

    void build(int node, int l, int r, const vector<int>& arr) {
        if (l == r) {
            tree[node] = arr[l];
            return;
        }
        int mid = (l + r) / 2;
        build(2*node, l, mid, arr);
        build(2*node+1, mid+1, r, arr);
        tree[node] = max(tree[2*node], tree[2*node+1]);
    }

    void update(int node, int l, int r, int idx, int val) {
        if (l == r) {
            tree[node] = val;
            return;
        }
        int mid = (l + r) / 2;
        if (idx <= mid) update(2*node, l, mid, idx, val);
        else update(2*node+1, mid+1, r, idx, val);
        tree[node] = max(tree[2*node], tree[2*node+1]);
    }

    int query(int node, int nl, int nr, int l, int r) {
        if (nr < l || nl > r) return 0;
        if (l <= nl && nr <= r) return tree[node];
        int mid = (nl + nr) / 2;
        return max(query(2*node, nl, mid, l, r), query(2*node+1, mid+1, nr, l, r));
    }

public:
    SegmentTree(const vector<int>& arr) {
        n = arr.size() - 1;
        tree.resize(4 * (n + 1));
        build(1, 1, n, arr);
    }

    void update(int idx, int val) {
        update(1, 1, n, idx, val);
    }

    int query(int l, int r) {
        return query(1, 1, n, l, r);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> parent(n + 1, -1);
    vector<vector<int>> children(n + 1);
    queue<int> q;
    q.push(1);
    parent[1] = -1;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : adj[u]) {
            if (parent[v] == -1 && v != parent[u]) {
                parent[v] = u;
                children[u].push_back(v);
                q.push(v);
            }
        }
    }

    vector<int> weight(n + 1);
    vector<Trie> tries(n + 1);

    for (int u = 1; u <= n; ++u) {
        if (children[u].empty()) {
            weight[u] = a[u];
        } else {
            for (int c : children[u]) {
                tries[u].insert(a[c]);
            }
            weight[u] = tries[u].queryMaxXOR(a[u]);;
        }
    }

    SegmentTree st(weight);

    while (m--) {
        int op;
        cin >> op;
        if (op == 1) {
            int u, x;
            cin >> u >> x;
            int old_a_u = a[u];
            a[u] = x;
            vector<int> affected;

            if (children[u].empty()) {
                if (x != weight[u]) {
                    affected.push_back(u);
                    weight[u] = x;
                }
            } else {
                int new_weight = tries[u].queryMaxXOR(x);
                if (new_weight != weight[u]) {
                    affected.push_back(u);
                    weight[u] = new_weight;
                }
            }

            int p = parent[u];
            if (p != -1) {
                tries[p].remove(old_a_u);
                tries[p].insert(x);
                int new_weight_p = tries[p].queryMaxXOR(a[p]);
                if (new_weight_p != weight[p]) {
                    affected.push_back(p);
                    weight[p] = new_weight_p;
                }
            }

            for (int node : affected) {
                st.update(node, weight[node]);
            }
        } else if (op == 2) {
            int x, y;
            cin >> x >> y;
            cout << st.query(x, y) << '\n';
        } else if (op == 3) {
            int u;
            cin >> u;
            cout << weight[u] << '\n';
        }
    }

    return 0;
}