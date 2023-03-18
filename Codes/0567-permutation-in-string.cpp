/*
 * @Author: LetMeFly
 * @Date: 2023-03-18 14:31:10
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-03-18 14:35:16
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    bool checkInclusion(string& s1, string& s2) {
        if (s1.size() > s2.size()) {
            return false;
        }
        vector<int> cnt1(26), cnt2(26);
        for (char c : s1) {
            cnt1[c - 'a']++;
        }
        for (int i = 0; i < s1.size(); i++) {
            cnt2[s2[i] - 'a']++;
        }
        if (cnt1 == cnt2) {
            return true;
        }
        for (int i = s1.size(); i < s2.size(); i++) {
            cnt2[s2[i] - 'a']++;
            cnt2[s2[i - s1.size()] - 'a']--;
            if (cnt1 == cnt2) {
                return true;
            }
        }
        return false;
    }
};