/*
 * @Author: LetMeFly
 * @Date: 2026-07-12 10:13:32
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-07-12 10:21:39
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<vector<int>> v = {
        {1, 2},
        {2, 3},
        {3, 4},
    };

    // 这里会编译错误！ GPT说可以并且好像在哪里见过一次才尝试的，实际g++ -std=c++17、20、23、26都不行
    for (auto& [a, b] : v) {
        cout << "(" << a << ", " << b << ")" << endl;
    }
    return 0;
}
