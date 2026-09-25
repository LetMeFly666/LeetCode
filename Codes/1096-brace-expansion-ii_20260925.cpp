/*
 * @Author: LetMeFly
 * @Date: 2026-09-25 08:10:14
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-09-25 08:28:29
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

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

class Solution {
private:
    Res dfs(string s) {
        
    }
public:
    vector<string> braceExpansionII(string expression) {
        Res res = dfs(expression);
        vector<string> ans(res.begin(), res.end());
        sort(ans.begin(), ans.end());
        return ans;
    }
};
