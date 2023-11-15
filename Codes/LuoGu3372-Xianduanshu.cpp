/*
 * @Author: LetMeFly
 * @Date: 2023-11-13 14:10:59
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-11-15 10:46:43
 * @WARN: update下一层后记得更新一下这一层 | query可能需要返回long long | 2n的空间不一定够用
 */
#include <bits/stdc++.h>
using namespace std;
#define mem(a) memset(a, 0, sizeof(a))
#define dbg(x) cout << #x << " = " << x << endl
#define fi(i, l, r) for (int i = l; i < r; i++)
#define cd(a) scanf("%d", &a)
typedef long long ll;
ll a[100010], tree[400010], mark[400010];  // 1 2 4 8 ... n | 2^0 2^1 ... 2^(log_2 n) | sum=1*(2^(log_2 n + 1)-1)/(2-1)=2n-1  但为什么2n不行呢？因为n不一定填满了最后一层
/*
例如6个元素1, 3, 5, 7, 9, 11
      36
     /  \
    9   27
   / \  /\
  4  5 16 11
 /\    /\
1 3 -- 7 9 
至少需要13个空间
*/

inline int lc(int p) {  // Left Child
    return p << 1;
}

inline int rc(int p) {
    return p << 1 | 1;
}

inline int gm(int l, int r) {  // get mid
    return (l + r) >> 1;
}

void delazy(int p, int l, int r) {
    int mid = gm(l, r);
    tree[lc(p)] += mark[p] * (mid - l + 1);
    tree[rc(p)] += mark[p] * (r - mid);
    mark[lc(p)] += mark[p];
    mark[rc(p)] += mark[p];
    mark[p] = 0;
}

void build(int p, int l, int r) {
    if (l == r) {
        tree[p] = a[l];
        return;
    }
    int mid = gm(l, r);
    build(lc(p), l, mid);
    build(rc(p), mid + 1, r);
    tree[p] = tree[lc(p)] + tree[rc(p)];
}

void update(int p, int l, int r, int x, int y, ll val) {
    if (r < x || l > y) {
        return;
    }
    if (l >= x && r <= y) {
        mark[p] += val;
        tree[p] += val * (r - l + 1);
        return;
    }
    delazy(p, l, r);
    int mid = gm(l, r);
    update(lc(p), l, mid, x, y, val);
    update(rc(p), mid + 1, r, x, y, val);
    tree[p] = tree[lc(p)] + tree[rc(p)];
}

ll query(int p, int l, int r, int x, int y) {
    if (r < x || l > y) {
        return 0;
    }
    if (l >= x && r <= y) {
        return tree[p];
    }
    delazy(p, l, r);
    int mid = gm(l, r);
    return query(lc(p), l, mid, x, y) + query(rc(p), mid + 1, r, x, y);
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
    }
    build(1, 1, n);
    while (m--) {
        int op, x, y;
        cd(op), cd(x), cd(y);
        switch (op)
        {
        case 1:
            ll val;
            scanf("%lld", &val);
            update(1, 1, n, x, y, val);
            break;
        
        case 2:
            printf("%lld\n", query(1, 1, n, x, y));
            break;
        }
    }
    return 0;
}