/*
 * @Author: LetMeFly
 * @Date: 2025-03-01 16:02:37
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-01 16:11:13
 * @Descriptions: AC,91.81%,95.10%
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    string s;
    vector<string> now;
    vector<vector<string>> ans;

    bool isok(int l, int r) {  // [l, r]
        for (; l < r; l++, r--) {
            if (s[l] != s[r]) {
                return false;
            }
        }
        return true;
    }

    void dfs(int l) {
        if (l == s.size()) {
            ans.push_back(now);
            return;
        }
        for (int r = l; r < s.size(); r++) {
            if (isok(l, r)) {
                now.push_back(s.substr(l, r - l + 1));
                dfs(r + 1);
                now.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        this->s = move(s);
        dfs(0);
        return move(ans);
    }
};