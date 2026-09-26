/*
 * @Author: LetMeFly
 * @Date: 2026-02-07 23:12:50
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-02-07 23:16:01
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int minimumDeletions(string s) {
        int remainA = count(s.begin(), s.end(), 'a'), alreadyB = 0;
        int ans = remainA;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'a') {
                remainA--;
            } else {
                alreadyB++;
            }
            ans = min(ans, remainA + alreadyB);
        }
        return ans;
    }
};