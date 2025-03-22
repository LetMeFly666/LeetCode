/*
 * @Author: LetMeFly
 * @Date: 2025-03-22 19:30:14
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-22 19:36:56
 */
// 诶，不是哥们，还没利用“排列中数各不相同的性质”呢，咋就84ms然后AC了
#include <bits/stdc++.h>
using namespace std;

int a[10010];

int solve(int n) {
    int ans = 0;
    for (int start = 0; start < n; start++) {
        int lt = 0, gt = 0;
        ans++;
        for (int i = 1; start - i >= 0 && start + i < n; i++) {
            if (a[start - i] > a[start]) {
                gt++;
            } else {
                lt++;
            }
            if (a[start + i] > a[start]) {
                gt++;
            } else {
                lt++;
            }
            ans += lt == gt;
        }
    }
    return ans;
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        int ans = solve(n);
        printf("%d\n", ans);
    }
    return 0;
}