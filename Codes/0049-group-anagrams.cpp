/*
 * @Author: LetMeFly
 * @Date: 2022-05-25 10:05:02
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-05-25 10:08:16
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>, vector<string>> ma;
        for (string& s : strs) {
            vector<int> appendTime(26, 0);
            for (char& c : s) {
                appendTime[c - 'a']++;
            }
            ma[appendTime].push_back(s);
        }
        vector<vector<string>> ans;
        for (auto& [a, vs] : ma) {
            ans.push_back(vs);
        }
        return ans;
    }
};