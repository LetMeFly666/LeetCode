/*
 * @Author: LetMeFly
 * @Date: 2025-03-19 22:33:43
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-19 22:37:10
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> ma;
        for (string& s : strs) {
            string sorted = s;
            sort(sorted.begin(), sorted.end());
            ma[sorted].push_back(s);
        }
        vector<vector<string>> ans;
        for (unordered_map<string, vector<string>>::iterator it = ma.begin(); it != ma.end(); it++) {
            ans.push_back(move(it->second));
        }
        return ans;
    }
};