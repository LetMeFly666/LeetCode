/*
 * @Author: LetMeFly
 * @Date: 2022-09-24 08:04:13
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-09-24 08:08:06
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> ans(n);
        if (k == 0)
            return ans;
        if (k > 0) {
            for (int i = 0; i < n; i++) {
                int s = 0;
                for (int j = 1; j <= k; j++) {
                    s += code[(i + j) % n];
                }
                ans[i] = s;
            }
        }
        else {
            for (int i = 0; i < n; i++) {
                int s = 0;
                for (int j = 1; j <= -k; j++) {
                    s += code[(i - j + n) % n];
                }
                ans[i] = s;
            }
        }
        return ans;
    }
};