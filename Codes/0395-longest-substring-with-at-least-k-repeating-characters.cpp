/*
 * @Author: LetMeFly
 * @Date: 2022-10-13 10:05:10
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-10-13 10:23:34
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    unordered_set<char> differentChar(string& s) {
        unordered_set<char> se;
        for (char c : s) {
            se.insert(c);
        }
        return se;
    }
public:
    int longestSubstring(string s, int k) {
        // printf("cal(%s)\n", s.c_str());
        for (char c : differentChar(s)) {
            if (count(s.begin(), s.end(), c) < k) {
                int ans = 0;
                int l = 0;
                for (int i = 0; i <= s.size(); i++) {
                    if (i == s.size() || s[i] == c) {
                        if (l < i) {
                            ans = max(ans, longestSubstring(s.substr(l, i - l), k));
                        }
                        l = i + 1;
                    }
                }
                return ans;
            }
        }
        return s.size();
    }
};