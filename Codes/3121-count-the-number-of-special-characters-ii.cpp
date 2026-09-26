/*
 * @Author: LetMeFly
 * @Date: 2026-05-27 22:18:15
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-05-27 22:33:20
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
        int ans = 0;
        for (char c : word) {
            bool small = 'a' <= c && c <= 'z';
            int idx = small ? c - 'a' : c - 'A';
            switch (state[idx]) {
            case NONE:
                state[idx] = small ? SMALL : CANNOT;
                break;
            case SMALL:
                if (!small) {
                    state[idx] = OK;
                    ans++;
                }
                break;
            case OK:
                if (small) {
                    state[idx] = CANNOT;
                    ans--;
                }
                break;
            }
        }
        return ans;
    }
};
