/*
 * @Author: LetMeFly
 * @Date: 2022-05-27 07:49:25
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-05-27 08:05:29
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int findClosest(vector<string>& words, string word1, string word2) {
        unordered_map<string, vector<int>> ma;
        for (int i = 0; i < words.size(); i++) {
            ma[words[i]].push_back(i);
        }
        vector<int>& loc1s = ma[word1];
        vector<int>& loc2s = ma[word2];
        if (loc1s.empty() || loc2s.empty()) {
            return -1;  // 题目好像没说不存在的情况
        }
        int ans = words.size();
        #ifdef FirstTry_Error_  // 二分出错
        for (int loc1 : loc1s) {
            vector<int>::iterator it = lower_bound(loc2s.begin(), loc2s.end(), loc1);
            if (it == loc2s.end()) {
                ans = min(ans, abs(loc1 - *--it));
            }
            else {
                ans = min(ans, abs(loc1 - *it));
                if (++it != loc2s.end()) {
                    ans = min(ans, abs(loc1 - *it));
                }
            }
        }
        #endif
        int locloc1 = 0, locloc2 = 0;
        while (locloc1 < loc1s.size() && locloc2 < loc2s.size()) {
            ans = min(ans, abs(loc1s[locloc1] - loc2s[locloc2]));
            if (loc1s[locloc1] < loc2s[locloc2]) {
                locloc1++;
            }
            else {
                locloc2++;
            }
        }
        return ans;
    }
};