/*
 * @Author: LetMeFly
 * @Date: 2023-02-21 21:25:49
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-03-03 19:56:36
 */
#include <bits/stdc++.h>
using namespace std;
#define mem(a) memset(a, 0, sizeof(a))
#define dbg(x) cout << #x << " = " << x << endl
#define fi(i, l, r) for (int i = l; i < r; i++)
#define cd(a) scanf("%d", &a)
typedef long long ll;

int a[10010];
int temp[10010];

void mergeSort(int l, int r) {
    if (l + 1 == r) {
        return;
    }
    int m = (l + r) >> 1;
    mergeSort(l, m);
    mergeSort(m, r);
    int ll = l, lr = m;  // loc l, loc r
    int lt = l;  // loc temp
    while (ll < m && lr < r) {
        if (a[ll] < a[lr]) {
            temp[lt++] = a[ll++];
        }
        else {
            temp[lt++] = a[lr++];
        }
    }
    while (ll < m) {
        temp[lt++] = a[ll++];
    }
    while (lr < r) {
        temp[lt++] = a[lr++];
    }
    for (int i = l; i < r; i++) {
        a[i] = temp[i];
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        mergeSort(0, n);
        for (int i = 0; i < n; i++) {
            printf("%d ", a[i]);
        }
        puts("");
    }    
    return 0;
}

/*
1
8
42 15 20 6 8 38 50 12

*/