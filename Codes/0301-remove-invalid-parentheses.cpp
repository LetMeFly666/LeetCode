/*
 * @Author: LetMeFly
 * @Date: 2021-10-27 22:34:57
 * @LastEditors: LetMeFly
 * @LastEditTime: 2021-10-27 23:13:05
 */
#include <bits/stdc++.h>
using namespace std;
#define mem(a) memset(a, 0, sizeof(a))
#define dbg(x) cout << #x << " = " << x << endl
#define fi(i, l, r) for (int i = l; i < r; i++)
#define cd(a) scanf("%d", &a)
typedef long long ll;

void debug(vector<string> v) {
    printf("[");
    bool first = true;
    for (string &s : v) {
        if (first) first = false;
        else putchar(',');
        cout << "\"" << s << "\"";
    }
    puts("]");
}

vector<string> getAviliable(vector<string> &v) {
    vector<string> ans;
    for (string &thisString : v) {
        int l = 0;
        for (char &c : thisString) {
            if (c == '(') {
                l++;
            } else if (c == ')') {
                l--;
                if (l < 0) {
                    goto loop;
                }
            }
        }
        if (l) continue;
        ans.push_back(thisString);
        loop:;
    }
    return ans;
}
vector<string> getMinmal(vector<string> &v) {
    int l = 0;
    for (string &s : v) {
        l = max(l, int(s.size()));
    }
    // dbg(l); //*****
    vector<string> ans;
    for (string &s: v) {
        if (s.length() == l) {
            ans.push_back(s);
        }
    }
    return ans;
}
class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> ans;
        int l = s.size();
        for (int i = 0; i < (1<<l); i++) {
            string thisS;
            for (int j = 0; j < l; j++) {
                if (i & (1 << j) || (s[j] != ')' && s[j] != '(')) {
                    thisS += s[j];
                }
            }
            ans.push_back(thisS);
        }
        // debug(ans); //**********
        sort(ans.begin(), ans.end());
        ans.erase(unique(ans.begin(), ans.end()), ans.end()); // 去重
        // debug(ans); //**********
        ans = getAviliable(ans);
        // debug(ans); //**********
        ans = getMinmal(ans);
        return ans;
    }
};

int main() {
    string s;
    while (cin >> s) {
        if (s.size() && s[0] == '"') {
            s = s.substr(1, s.size() - 1);
        }
        if (s.size() && s[s.size() - 1] == '"') {
            s = s.substr(0, s.size() - 1);
        }
        Solution sol;
        debug(sol.removeInvalidParentheses(s));
    }
    return 0;
}