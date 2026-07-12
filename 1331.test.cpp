/*
 * @Author: LetMeFly
 * @Date: 2026-07-12 09:55:00
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-07-12 09:57:05
 */
#include <bits/stdc++.h>
using namespace std;

// sort一个空数组确实是可行的
int main() {
    vector<int> empty;
    sort(empty.begin(), empty.end());
    cout << empty.size() << endl;
    return 0;
}
