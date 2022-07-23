/*
 * @Author: LetMeFly
 * @Date: 2022-07-23 11:50:50
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-07-23 11:56:43
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    inline bool ok(string& s) {
        for (int i = 0; i < s.size() / 2; i++) {
            if (s[i] != s[s.size() - i - 1])
                return false;
        }
        return true;
    }
public:
    vector<vector<string>> partition(string s) {
        int n = s.size() - 1;
        vector<vector<string>> ans;
        for (int i = 0; i < (1 << n); i++) {
            int lastLoc = 0;
            vector<string> thisSplited;
            string thisStr;
            for (int j = 0; j < n; j++) {
                if (i & (1 << j)) {
                    thisStr = s.substr(lastLoc, j + 1 - lastLoc);
                    if (!ok(thisStr)) {
                        goto loop;
                    }
                    thisSplited.push_back(thisStr);
                    lastLoc = j + 1;
                }
            }
            thisStr = s.substr(lastLoc, s.size() - lastLoc);
            if (!ok(thisStr))
                goto loop;
            thisSplited.push_back(thisStr);
            ans.push_back(thisSplited);
            loop:;
        }
        return ans;
    }
};