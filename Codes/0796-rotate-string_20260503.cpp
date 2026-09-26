/*
 * @Author: LetMeFly
 * @Date: 2026-05-03 17:21:12
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-05-03 17:22:50
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    int n;

    bool ok(const string& s, const string& goal, int diff) {
        for (int i = 0; i < n; i++) {
            if (s[(i + diff) % n] != goal[i]) {
                return false;
            }
        }
        return true;
    }
public:
    bool rotateString(const string& s, const string& goal) {
        n = s.size();
        if (goal.size() != n) {
            return false;
        }
        for (int i = 0; i < n; i++) {
            if (ok(s, goal, i)) {
                return true;
            }
        }
        return false;
    }
};
