/*
 * @Author: LetMeFly
 * @Date: 2023-01-12 22:15:05
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-01-12 22:21:28
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        string ans;
        unordered_map<string, string> ma;
        for (auto& v : knowledge) {
            ma[v[0]] = v[1];
        }
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                int to = i + 1;
                while (s[to] != ')') {
                    to++;
                }
                string key = s.substr(i + 1, to - i - 1);
                ans += ma.count(key) ? ma[key] : "?";
                i = to;  // 循环结束后会有i++
            }
            else {
                ans += s[i];
            }
        }
        return ans;
    }
};