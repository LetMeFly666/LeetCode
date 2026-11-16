/*
 * @Author: LetMeFly
 * @Date: 2026-11-16 21:51:47
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-11-16 21:57:46
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    string digitSum(string s, int k) {
        while (s.size() > k) {
            string tmp;
            int cnt = 0;
            for (int i = 0, n = s.size(); i < n; i++) {
                if (i && i % k == 0) {
                    tmp += to_string(cnt);
                    cnt = 0;
                }
                cnt += s[i] - '0';
            }
            tmp += to_string(cnt);
            swap(s, tmp);
        }
        return s;
    }
};
