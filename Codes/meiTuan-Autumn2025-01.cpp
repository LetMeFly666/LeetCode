/*
 * @Author: LetMeFly
 * @Date: 2025-09-06 10:17:35
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-09-06 10:18:48
 */
#include <iostream>
#include <set>
#include <unordered_set>
using namespace std;

int main() {
    string s;
    cin >> s;
    unordered_set<string> se;
    int last = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'd') {
            se.insert(s.substr(last, i - last));
            last = i + 2;
        }
    }
    cout << se.size() << endl;
    return 0;
}