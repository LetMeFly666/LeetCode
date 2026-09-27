/*
 * @Author: LetMeFly
 * @Date: 2026-09-27 08:22:09
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-09-27 08:49:50
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

/*
(ed(et(oc))el)
[ed          ]
[ed        te]
[ed oc     te]
[ed oc  le te]
    两栈不可
*/
class Solution {
private:
    size_t find_end(string_view s, size_t left) {
        size_t idx = left + 1;
        for (size_t layer = 1; layer; idx++) {
            if (s[idx] == '(') {
                layer++;
            } else if (s[idx] == ')') {
                layer--;
            }
        }
        return --idx;
    }

    string dfs(string_view s) {
        string ans;
        for (size_t i = 0, n = s.size(); i < n; i++) {
            if (s[i] == '(') {
                size_t end = find_end(s, i);
                string res = dfs(s.substr(i + 1, end - i - 1));
                reverse(res.begin(), res.end());
                ans += res;
                i = end;
            } else {
                ans += s[i];
            }
        }
        return ans;
    }
public:
    string reverseParentheses(const string& s) {
        return dfs(s);
    }
};

#ifdef _DEBUG
/*
(abcd)
(u(love)i)
(ed(et(oc))el)
ta()usw((((a))))
*/
int main() {
    string s;
    while (cin >> s) {
        Solution sol;
        cout << sol.reverseParentheses(s) << endl;
    }
    return 0;
}
#endif
