/*
 * @Author: LetMeFly
 * @Date: 2023-02-21 21:25:49
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-03-03 19:49:07
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
    // printf("l = %d, r = %d\n", l, r);  //*********
    if (l + 1 >= r)
        return;
    int to = (l + r) >> 1;
    mergeSort(l, to);
    mergeSort(to, r);
    int l1 = l, l2 = to;
    int lt = 0;
    while (l1 < to && l2 < r) {
        if (a[l1] < a[l2])
            temp[lt++] = a[l1++];
        else
            temp[lt++] = a[l2++];
    }
    while (l1 < to) {
        temp[lt++] = a[l1++];
    }
    while (l2 < r) {
        temp[lt++] = a[l2++];
    }
    // swap(a, temp);  // 不可！temp中有很多的0
    for (int i = l, lt = 0; i < r; i++, lt++) {
        a[i] = temp[lt];
    }
    // printf("l = %d, r = %d", l, r);  //***********
    // for (int i = l; i < r; i++) {  //***********
    //     printf(", a[%d] = %d", i, a[i]);  //***********
    // }  //***********
    // puts("");  //***********
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