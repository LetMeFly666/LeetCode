/*
 * @Author: LetMeFly
 * @Date: 2025-03-22 19:46:01
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-22 20:04:16
 */
#include <bits/stdc++.h>

using namespace std;

int n, k;

bool a[1000010], b[1000010];

int main() {
    cin >> n >> k;
    string s;
    cin >> s;
    a[k] = true;
    for (char c : s) {
        if (c == 'L' || c == '?') {
            for (int i = 2; i <= n; i++) {
                if (a[i]) {
                    b[i - 1] = true;
                }
            }
            if (a[1]) {
                b[1] = true;
            }
        }
        if (c == 'R' || c == '?') {
            for (int i = 1; i < n; i++) {
                if (a[i]) {
                    b[i + 1] = true;
                }
            }
            if (a[n]) {
                b[n] = true;
            }
        }
        swap(a, b);
    }
    for (int i = 1; i <= n; i++) {
        putchar(a[i] ? '1' : '0');
    }
    return 0;
}