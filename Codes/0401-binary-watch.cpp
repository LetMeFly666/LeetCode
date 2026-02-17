/*
 * @Author: LetMeFly
 * @Date: 2026-02-17 11:05:25
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-02-17 11:11:11
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> ans;
        for (int h = 0; h < 12; h++) {
            for (int m = 0; m < 60; m++) {
                if (__builtin_popcount(h) + __builtin_popcount(m) == turnedOn) {
                    ans.push_back(format("{}:{:02}", h, m));
                }
            }
        }
        return ans;
    }
};