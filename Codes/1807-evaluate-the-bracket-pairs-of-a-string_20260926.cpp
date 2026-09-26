/*
 * @Author: LetMeFly
 * @Date: 2026-09-26 09:29:26
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-09-26 09:34:05
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    string evaluate(const string& s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> ma;
        for (vector<string>& v : knowledge) {
            ma[v[0]] = v[1];
        }
        string ans;
        for (int i = 0, n = s.size(); i < n; i++) {
            if (s[i] == '(') {
                int next_i = s.find_first_of(')', i);  // 不应为nops
                string key = s.substr(i + 1, next_i - i - 1);
                ans += ma.count(key) ? ma[key] : "?";
                i = next_i;
            } else {
                ans += s[i];
            }
        }
        return ans;
    }
};
