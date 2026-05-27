/*
 * @Author: LetMeFly
 * @Date: 2026-05-27 22:18:15
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-05-27 22:27:21
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

enum State {
    NONE,
    SMALL,
    OK,
    CANNOT,
};

class Solution {
public:
    int numberOfSpecialChars(string word) {
        State state[26];
        int ans = 0, all = 0;
        for (char c : word) {
            bool small = 'a' <= c && c <= 'z';
            int idx = small ? c - 'a' : c - 'A';
            if (state[idx] == NONE) {
                all++;
                state[idx] = small ? SMALL : CANNOT;
                if (all == 26) {
                    break;
                }
            } else if (state[idx] == SMALL && !small) {
                ans++;
                state[idx] = OK;
            }
        }
        return ans;
    }
};
