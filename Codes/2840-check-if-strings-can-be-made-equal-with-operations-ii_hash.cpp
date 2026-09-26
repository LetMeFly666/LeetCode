/*
 * @Author: LetMeFly
 * @Date: 2026-03-30 09:25:57
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-03-30 09:32:52
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    bool checkStrings(const string& s1, const string& s2) {
        int n = s1.size();
        int cnt[2][26] = {0};
        for (int i = 0; i < n; i++) {
            cnt[i % 2][s1[i] - 'a']++;
            cnt[i % 2][s2[i] - 'a']--;
        }
        
        for (int i = 0; i < 26; i++) {
            if (cnt[0][i] || cnt[1][i]) {
                return false;
            }
        }
        return true;
    }
};