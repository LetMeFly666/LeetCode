/*
 * @Author: LetMeFly
 * @Date: 2026-08-26 07:55:52
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-08-26 14:07:19
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    void update(string& ans, string& s, int l, int r) {
        std::string_view cur(s.data() + l, r - l + 1);
        if (ans.empty() || r - l + 1 < ans.size() || ans < cur) {
            ans = s.substr(l, r - l + 1);
        }
    }
public:
    string shortestBeautifulSubstring(string& s, int k) {
        string ans;
        for (int l = 0, r = 0, cnt = 0, n = s.size(); r < n; r++) {
            cnt += s[r] == '1';
            while (cnt > k) {
                cnt -= s[l++] == '1';
            }
            if (cnt == k) {
                update(ans, s, l, r);
            }
        }
        return ans;
    }
};
