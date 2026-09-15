/*
 * @Author: LetMeFly
 * @Date: 2026-09-15 14:29:03
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-09-15 16:51:02
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    bool ok(string& s, int l, int r) {  // [l, r)
        // len->i: 3->1 4->2 5->2 6->3
        for (int i = 0; i < (r - l) / 2; i++) {
            if (s[l + i] != s[r - i]) {
                return false;
            }
        }
        return true;
    }
public:
    int maxPalindromes(string& s, int k) {
        int n = s.size();
        vector<int> f(n + 1);
        for (int i = k; i <= n; i++) {
            f[i] = f[i - 1];
            if (ok(s, i - k, i)) {
                f[i] = max(f[i], f[i - k] + 1);
            }
            if (i != k && ok(s, i - k - 1, i)) {
                f[i] = max(f[i], f[i - k - 1]);
            }
        }
        return f.back();
    }
};
