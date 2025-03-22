/*
 * @Author: LetMeFly
 * @Date: 2025-03-22 20:05:24
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-22 20:05:24
 */
#include <bits/stdc++.h>

using namespace std;

int n, k;

bool a[1000010], b[1000010];

int main() {
    cin >> n >> k;
    string s;
    cin >> s;
    // a[k] = true;
    // for (char c : s) {
    //     if (c == 'L' || c == '?') {
    //         for (int i = 2; i <= n; i++) {
    //             if (a[i]) {
    //                 b[i - 1] = true;
    //             }
    //         }
    //         if (a[1]) {
    //             b[1] = true;
    //         }
    //     }
    //     if (c == 'R' || c == '?') {
    //         for (int i = 1; i < n; i++) {
    //             if (a[i]) {
    //                 b[i + 1] = true;
    //             }
    //         }
    //         if (a[n]) {
    //             b[n] = true;
    //         }
    //     }
    //     swap(a, b);
    // }
    for (int i = 1; i <= n; i++) {
        putchar('1');
    }
    return 0;
}