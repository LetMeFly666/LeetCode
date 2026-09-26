/*
 * @Author: LetMeFly
 * @Date: 2026-09-25 08:10:14
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-09-26 13:08:14
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

// struct Res : unordered_set<string> {
//     Res() : unordered_set<string>{""} {}
// };
typedef unordered_set<string> Res;

Res operator* (const Res& a, const Res& b) {
    Res res;
    for (const string& s1 : a) {
        for (const string& s2 : b) {
            res.insert(s1 + s2);
        }
    }
    return res;
}

Res& operator+= (Res& a, const Res& b) {
    a.insert(b.begin(), b.end());
    return a;
}

typedef vector<int> Idx;

class Solution {
private:
    // 最外层是加法运算
    Idx getAdd(string_view s) {
        Idx idxs;
        int layer = 0;
        for (int i = 0, n = s.size(); i < n; i++) {
            if (s[i] == '{') {
                layer++;
            } else if (s[i] == '}') {
                layer--;
            } else if (s[i] == ',' && !layer) {
                idxs.push_back(i);
            }
        }
        return idxs;
    }

    Idx getMul(string_view s) {
        Idx idxs;
        int layer = 0;
        for (int i = 0, n = s.size(); i < n; i++) {
            if (!layer && i && (s[i - 1] == '}' || s[i] == '{')) {
                idxs.push_back(i);
            }
            if (s[i] == '{') {
                layer++;
            } else if (s[i] == '}') {
                layer--;
            }
        }
        return idxs;
    }

    Res dfs(string_view s) {
        Res res;
        Idx idxs = getAdd(s);
        if (idxs.size()) {  // 最外层是加法运算
            idxs.push_back(s.size());
            int last_idx = -1;
            for (int idx : idxs) {
                res += dfs(s.substr(last_idx + 1, idx - last_idx - 1));
                last_idx = idx;
            }
            return res;
        }
        // 最外层是乘法运算(或单个字符串)
        idxs = getMul(s);
        if (idxs.empty() && s.size() && s[0] != '{') {  // 没有括号，那就是单个字符串
            res.insert(string(s));
            return res;
        }
        if (idxs.empty()) {  // 只有最外层一个大括号，如 {a,b}
            return dfs(s.substr(1, s.size() - 2));
        }
        idxs.push_back(s.size());
        int last_idx = 0;
        res.insert("");
        for (int idx : idxs) {
            res = res * dfs(s.substr(last_idx, idx - last_idx));
            last_idx = idx;
        }
        return res;
    }
public:
    vector<string> braceExpansionII(string expression) {
        Res res = dfs(expression);
        vector<string> ans(res.begin(), res.end());
        sort(ans.begin(), ans.end());
        return ans;
    }
};

/*
c{a{b}}d
{{a,z},a{b,c},{ab,z}}
{ab,c}{d},{e}
a{b,c}
{a,b}c
{a}b
{a}
d,a{b,c}
*/

#ifdef _DEBUG
int main() {
    string s;
    while (cin >> s) {
        Solution sol;
        debug(sol.braceExpansionII(s));
    }
    return 0;
}
#endif
