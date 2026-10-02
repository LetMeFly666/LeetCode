/*
 * @Author: LetMeFly
 * @Date: 2026-10-02 16:38:09
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-10-02 16:54:44
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    vector<string> ans;

    void dfs(string& s, int idx, int diff, int left, int right) {
        if (!left && !right) {
            ans.push_back(s);
        }
        if (left) {
            s[idx] = '(';
            dfs(s, idx + 1, diff + 1, left - 1, right);
        }
        if (diff && right) {
            s[idx] = ')';
            dfs(s, idx + 1, diff - 1, left, right - 1);
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        string s(n * 2, ' ');
        dfs(s, 0, 0, n, n);
        return ans;
    }
};
