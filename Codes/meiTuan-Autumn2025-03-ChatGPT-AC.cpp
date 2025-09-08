#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// AI coding
const int MAXB = 30; // 0..30 covers up to ~1e9

// --- XOR TRIE POOL (multiple tries share a global node pool) ---
struct TriePool {
    vector<array<int,2>> ch;
    vector<int> cnt; // how many numbers go through this node
    TriePool() {
        ch.reserve(3100000); // will expand as needed
        cnt.reserve(3100000);
        // make index 0 as "null" (we will not use it as real node).
        // but easier: create node 1 as first real node; root indices start at 0 meaning empty.
        ch.push_back({0,0});
        cnt.push_back(0);
    }
    int newNode(){
        ch.push_back({0,0});
        cnt.push_back(0);
        return (int)ch.size()-1;
    }
    // insert value into trie with root index & update counts; if root==0 create new root and return it
    int insert_val(int root, int val, int delta){
        if(root==0){
            root = newNode();
        }
        int node = root;
        cnt[node] += delta;
        for(int b = MAXB; b>=0; --b){
            int bit = (val>>b)&1;
            if(ch[node][bit]==0){
                ch[node][bit] = newNode();
            }
            node = ch[node][bit];
            cnt[node] += delta;
        }
        return root;
    }
    // query max xor with val on trie rooted at root; assume root!=0 and cnt[root]>0
    int query_max(int root, int val){
        if(root==0 || cnt[root] <= 0) return -1; // empty
        int node = root;
        int res = 0;
        for(int b=MAXB;b>=0;--b){
            int bit = (val>>b)&1;
            int want = bit^1;
            if(ch[node][want] != 0 && cnt[ch[node][want]] > 0){
                res |= (1<<b);
                node = ch[node][want];
            }else{
                node = ch[node][bit];
                if(node==0) break;
            }
        }
        return res;
    }
} pool;

// --- Segment Tree for range maximum (point update) ---
struct SegTree {
    int n;
    vector<int> st;
    SegTree(){}
    SegTree(int _n){ init(_n); }
    void init(int _n){
        n = _n;
        st.assign(4*n+10, INT_MIN);
    }
    void build(vector<int> &a){ build(1,1,n,a); }
    void build(int p,int l,int r, vector<int>&a){
        if(l==r){
            st[p] = a[l];
            return;
        }
        int m=(l+r)>>1;
        build(p<<1,l,m,a);
        build(p<<1|1,m+1,r,a);
        st[p]=max(st[p<<1], st[p<<1|1]);
    }
    void point_update(int idx,int val){ update(1,1,n,idx,val); }
    void update(int p,int l,int r,int idx,int val){
        if(l==r){ st[p]=val; return; }
        int m=(l+r)>>1;
        if(idx<=m) update(p<<1,l,m,idx,val);
        else update(p<<1|1,m+1,r,idx,val);
        st[p]=max(st[p<<1], st[p<<1|1]);
    }
    int range_max(int L,int R){ return query(1,1,n,L,R); }
    int query(int p,int l,int r,int L,int R){
        if(R<l || r<L) return INT_MIN;
        if(L<=l && r<=R) return st[p];
        int m=(l+r)>>1;
        return max(query(p<<1,l,m,L,R), query(p<<1|1,m+1,r,L,R));
    }
};

// ---------- main ----------
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    if(!(cin>>n>>m)) return 0;
    vector<int> a(n+1);
    for(int i=1;i<=n;++i) cin>>a[i];
    vector<vector<int>> adj(n+1);
    for(int i=0;i<n-1;++i){
        int u,v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // compute parent, children lists and Euler tour (non-recursive)
    vector<int> parent(n+1,0);
    vector<vector<int>> children(n+1);
    vector<int> order; order.reserve(n);
    // BFS/stack from root=1 to set parent (iterative DFS)
    vector<int> st; st.reserve(n);
    st.push_back(1);
    parent[1]= -1; // mark root parent as -1
    while(!st.empty()){
        int u = st.back(); st.pop_back();
        order.push_back(u);
        for(int v: adj[u]){
            if(parent[v]==0){
                parent[v]=u;
                st.push_back(v);
            }
        }
    }
    // build children lists (parent[root] was set to -1)
    for(int v=2;v<=n;++v){
        int p = parent[v];
        children[p].push_back(v);
    }

    // Euler tour tin/tout (iterative)
    vector<int> tin(n+1), tout(n+1);
    int timer=0;
    // iterative stack for entry/exit
    vector<pair<int,int>> stack2; // (node, next_child_index) for DFS
    stack2.emplace_back(1, 0);
    while(!stack2.empty()){
        auto &pr = stack2.back();
        int u = pr.first;
        int &ci = pr.second;
        if(ci==0){
            tin[u] = ++timer;
        }
        if(ci < (int)children[u].size()){
            int v = children[u][ci++];
            stack2.emplace_back(v,0);
        }else{
            tout[u] = timer;
            stack2.pop_back();
        }
    }

    // per-node trie roots (index into pool), init 0 meaning empty
    vector<int> troots(n+1, 0);
    // initially insert each child value into parent's trie
    for(int u=1;u<=n;++u){
        for(int v : children[u]){
            troots[u] = pool.insert_val(troots[u], a[v], +1);
        }
    }

    // compute initial weight w[u]
    vector<int> w(n+1, 0);
    for(int u=1;u<=n;++u){
        if(troots[u]==0 || pool.cnt[troots[u]]<=0){
            w[u] = a[u];
        }else{
            int best = pool.query_max(troots[u], a[u]);
            if(best < 0) w[u] = a[u];
            else w[u] = best;
        }
    }

    // build two segment trees
    SegTree seg_id, seg_euler;
    seg_id.init(n);
    seg_euler.init(n);
    // prepare arrays (1-based)
    vector<int> arr_id(n+1), arr_euler(n+1);
    for(int u=1;u<=n;++u){
        arr_id[u] = w[u];
        arr_euler[tin[u]] = w[u];
    }
    seg_id.build(arr_id);
    seg_euler.build(arr_euler);

    // process operations
    for(int qi=0; qi<m; ++qi){
        int type; cin>>type;
        if(type==1){
            int x; int y; cin>>x>>y;
            int old = a[x];
            if(old == y){
                a[x] = y; // still set
                // still need to recompute w[x] and w[parent] because even if value same nothing changes;
                // but since nothing changed, we can skip heavy work. However keeping correct:
                // skip full updates if no change.
                continue;
            }
            a[x] = y;
            int p = parent[x];
            if(p>0){
                // remove old from p's trie, insert new
                troots[p] = pool.insert_val(troots[p], old, -1);
                troots[p] = pool.insert_val(troots[p], y, +1);
                // recompute w[p]
                int newwp;
                if(troots[p]==0 || pool.cnt[troots[p]]<=0) newwp = a[p];
                else {
                    int q = pool.query_max(troots[p], a[p]);
                    newwp = (q<0? a[p] : q);
                }
                if(newwp != w[p]){
                    w[p] = newwp;
                    seg_id.point_update(p, w[p]);
                    seg_euler.point_update(tin[p], w[p]);
                }
            }
            // recompute w[x] (its children unchanged)
            int newwx;
            if(troots[x]==0 || pool.cnt[troots[x]]<=0) newwx = a[x];
            else{
                int q = pool.query_max(troots[x], a[x]);
                newwx = (q<0? a[x] : q);
            }
            if(newwx != w[x]){
                w[x] = newwx;
                seg_id.point_update(x, w[x]);
                seg_euler.point_update(tin[x], w[x]);
            }
        }else if(type==2){
            int l,r; cin>>l>>r;
            if(l>r) swap(l,r);
            int ans = seg_id.range_max(l,r);
            cout<<ans<<"\n";
        }else if(type==3){
            int x; cin>>x;
            int ans = seg_euler.range_max(tin[x], tout[x]);
            cout<<ans<<"\n";
        }
    }

    return 0;
}
