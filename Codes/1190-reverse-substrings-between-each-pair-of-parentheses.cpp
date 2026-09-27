/*
 * @Author: LetMeFly
 * @Date: 2026-09-27 08:22:09
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-09-27 08:39:14
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
    string dfs(string_view s) {
        size_t begin = s.find('(');
        if (begin == s.npos) {
            return string(s);
        }
        string ans = string(s.substr(0, begin));
        size_t end = s.rfind(')');
        string middle = dfs(s.substr(begin + 1, end - begin - 1));
        reverse(middle.begin(), middle.end());
        ans += middle;
        ans += string(s.substr(end + 1, s.size() - end - 1));
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
