/*
 * @Author: LetMeFly
 * @Date: 2024-12-20 20:56:59
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2024-12-20 20:57:22
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    vector<int> count(string& s, int l, int r) {
        vector<int> ans(26);
        for (int i = l; i < r; i++) {
            ans[s[i] - 'a']++;
        }
        return ans;
    }
public:
    int minAnagramLength(string& s) {
        for (int ans = 1; ans < s.size(); ans++) {
            if (s.size() % ans) {
                continue;
            }
            vector<int> should = count(s, 0, ans);
            for (int i = ans; i < s.size(); i += ans) {
                vector<int> now = count(s, i, i + ans);
                if (should != now) {
                    goto loop;
                }
            }
            return ans;
            loop:;
        }
        return s.size();
    }
};