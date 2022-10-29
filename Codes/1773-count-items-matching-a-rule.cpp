/*
 * @Author: LetMeFly
 * @Date: 2022-10-29 08:51:48
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-10-29 08:53:24
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int countMatches(vector<vector<string>>& items, string& ruleKey, string& ruleValue) {
        int ans = 0;
        int th = (ruleKey == "type") ? 0 : (ruleKey == "color" ? 1 : 2);
        for (auto& item : items) {
            ans += item[th] == ruleValue;
        }
        return ans;
    }
};