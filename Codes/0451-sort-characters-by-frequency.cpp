/*
 * @Author: LetMeFly
 * @Date: 2022-10-21 20:39:18
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-10-21 20:40:22
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    string frequencySort(string& s) {
        int cnt[256] = {0};
        for (char c : s)
            cnt[c]++;
        sort(s.begin(), s.end(), [&](const char& a, const char& b) {
            return cnt[a] == cnt[b] ? a > b : cnt[a] > cnt[b];
        });
        return s;
    }
};