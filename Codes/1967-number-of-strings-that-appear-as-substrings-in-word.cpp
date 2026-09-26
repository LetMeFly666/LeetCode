/*
 * @Author: LetMeFly
 * @Date: 2026-06-29 15:07:05
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-06-29 15:07:50
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int numOfStrings(vector<string>& patterns, string& word) {
        int ans = 0;
        for (string& p : patterns) {
            ans += word.contains(p);
        }
        return ans;
    }
};
