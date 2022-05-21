/*
 * @Author: LetMeFly
 * @Date: 2021-10-31 00:02:08
 * @LastEditors: LetMeFly
 * @LastEditTime: 2021-10-31 00:05:44
 */
#include <bits/stdc++.h>
using namespace std;
#define mem(a) memset(a, 0, sizeof(a))
#define dbg(x) cout << #x << " = " << x << endl
#define fi(i, l, r) for (int i = l; i < r; i++)
#define cd(a) scanf("%d", &a)
typedef long long ll;
map<char, int> ma;
void init() {
    static int first = 0;
    if (first) return;
    first++;
    string f = "qwertyuiop";
    for (char c: f) {
        ma[c] = ma[c - 'a' + 'A'] = 1;
    }
    f = "asdfghjkl";
    for (char c: f) {
        ma[c] = ma[c - 'a' + 'A'] = 2;
    }
    f = "zxcvbnm";
    for (char c: f) {
        ma[c] = ma[c - 'a' + 'A'] = 3;
    }
}
class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        init();
        vector<string> ans;
        for (string &s:words) {
            int lineNum = ma[s[0]];
            for (char c: s) {
                if (ma[c] != lineNum) {
                    goto loop;
                }
            }
            ans.push_back(s);
            loop:;
        }
        return ans;
    }
};