/*
 * @Author: LetMeFly
 * @Date: 2026-10-02 16:38:09
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-10-02 16:43:41
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        n *= 2;
        for (int i = 0, to = 1 << n; i < to; i++) {
            string s(n, '0');
            bool ok = true;
            int cnt_left = 0;
            for (int j = 0; j < n; j++) {
                if (i >> j & 1) {
                    cnt_left++;
                    s[j] = '(';
                } else if (!cnt_left) {
                    ok = false;
                    break;
                } else {
                    cnt_left--;
                    s[j] = ')';
                }
            }
            if (cnt_left) {
                continue;
            }
            if (ok) {
                ans.push_back(s);
            }
        }
        return ans;
    }
};

#ifdef _DEBUG
int main() {
    int n;
    while (cin >> n) {
        Solution sol;
        debug(sol.generateParenthesis(n));
    }
    return 0;
}
#endif
