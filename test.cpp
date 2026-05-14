/*
 * @Author: LetMeFly
 * @Date: 2026-05-13 12:08:45
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-05-14 17:23:22
 */
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    vector<string> v;
    v.push_back("hello");
    v.push_back("world");

    cout << v[0] << endl;

    int n;
    cin >> n;
    cout << n << endl;
    return 0;
}
