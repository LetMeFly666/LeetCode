/*
 * @Author: LetMeFly
 * @Date: 2023-11-13 14:10:59
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-11-13 14:16:15
 */
#include <bits/stdc++.h>
using namespace std;
#define mem(a) memset(a, 0, sizeof(a))
#define dbg(x) cout << #x << " = " << x << endl
#define fi(i, l, r) for (int i = l; i < r; i++)
#define cd(a) scanf("%d", &a)
typedef long long ll;

ll A[100010], tree[200010], mark[200010];
int n;

int build(int l, int r, int p) {

}

int main() {
    int m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cd(A[i]);
    }
    build(1, 1, 1);
    return 0;
}