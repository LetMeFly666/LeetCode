/*
 * @Author: LetMeFly
 * @Date: 2026-04-15 23:08:45
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-04-15 23:14:35
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif
// THIS CANNOT BE ACCEPTED
class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        for (int i = 0, n = words.size(), to = n / 2; i < to; i++) {
            if (words[(startIndex + i) % n] == target || words[(startIndex - i + n) % n] == target) {
                return i;
            }
        }
        return -1;
    }
};
