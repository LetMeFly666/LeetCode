/*
 * @Author: LetMeFly
 * @Date: 2026-08-26 07:55:52
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-08-26 14:14:52
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    void update(string& ans, string& s, int l, int r) {
        int len = r - l + 1;
        std::string_view cur(s.data() + l, len);
        if (ans.empty() || len < ans.size() || len == ans.size() && ans < cur) {
            ans = cur;
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
                while (s[l] == '0') {  // do not forget!
                    l++;
                }
                update(ans, s, l, r);
            }
        }
        return ans;
    }
};
