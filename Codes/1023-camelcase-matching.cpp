/*
 * @Author: LetMeFly
 * @Date: 2023-04-14 13:41:16
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-04-14 13:51:07
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    bool isOK(string& q, string& pattern) {
        int locP = 0;
        for (char c : q) {
            if (locP < pattern.size() && pattern[locP] == c) {
                locP++;
            }
            else if (isupper(c)) {
                return false;
            }
        }
        return locP == pattern.size();
    }

public:
    vector<bool> camelMatch(vector<string>& queries, string& pattern) {
        vector<bool> ans(queries.size());
        for (int i = 0; i < queries.size(); i++) {
            ans[i] = isOK(queries[i], pattern);
        }
        return ans;
    }
};