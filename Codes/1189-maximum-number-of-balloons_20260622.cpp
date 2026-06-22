/*
 * @Author: LetMeFly
 * @Date: 2026-06-22 19:41:14
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-06-22 19:44:41
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int cnt[26] = {0};
        for (char c : text) {
            cnt[c - 'a']++;
        }
        return min(cnt['b' - 'a'], 
            min(cnt['a' - 'a'],
            min(cnt['l' - 'a'] / 2,
            min(cnt['o' - 'a'] / 2,
            cnt['n' - 'a'])
        )));
    }
};
