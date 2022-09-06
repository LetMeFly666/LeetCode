/*
 * @Author: LetMeFly
 * @Date: 2022-09-06 10:03:23
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-09-06 10:45:33
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int uniqueLetterString(string& s) {
        int n = s.size();
        vector<int> location[26];
        for (int i = 0; i < 26; i++) {
            location[i].push_back(-1);
        }
        for (int i = 0; i < n; i++) {
            location[s[i] - 'A'].push_back(i);
        }
        for (int i = 0; i < 26; i++) {
            location[i].push_back(n);
        }
        int ans = 0;
        for (int i = 0; i < 26; i++) {
            if (location[i].size() == 2)
                continue;
            for (int j = 1; j + 1 < location[i].size(); j++) {
                ans += (location[i][j] - location[i][j - 1]) * (location[i][j + 1] - location[i][j]);
            }
        }
        return ans;
    }
};