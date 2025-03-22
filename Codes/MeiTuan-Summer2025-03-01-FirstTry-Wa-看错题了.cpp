/*
 * @Author: LetMeFly
 * @Date: 2025-03-22 19:40:10
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-22 19:44:01
 */
#include <bits/stdc++.h>

using namespace std;

int n, k;

inline int update(int now) {
    if (now < 1) {
        return 1;
    }
    if (now > n) {
        return n;
    }
    return now;
}

int main() {
    cin >> n >> k;
    string s;
    cin >> s;
    int l = k, r = k;
    // int ans = 0;
    for (char c : s) {
        if (c == 'L') {
            l = update(l - 1);
            r = update(r - 1);
        } else if (c == 'R') {
            l = update(l + 1);
            r = update(r + 1);
        } else {
            l = update(l - 1);
            r = update(r + 1);
        }
        // ans += l == 1 || r == n;
        if (l == 1 || r == n) {
            putchar('1');
        } else {
            putchar('0');
        }
    }
    // cout << ans << endl;
    puts("");
    return 0;
}