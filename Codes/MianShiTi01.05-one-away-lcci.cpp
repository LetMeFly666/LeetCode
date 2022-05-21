/*
 * @Author: LetMeFly
 * @Date: 2022-05-13 14:07:05
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-05-13 14:12:45
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    bool oneEditAway(string& first, string& second) {
        if (second.size() + 1 == first.size()) {
            swap(first, second);
        }
        if (first.size() + 1 == second.size()) {
            bool changed = false;
            int locSecond = 0;
            for (int i = 0; i < first.size(); i++) {
                if (first[i] != second[locSecond++]) {
                    if (changed)
                        return false;
                    changed = true;
                    i--;
                }
            }
            return true;
        }
        else if (second.size() == first.size()) {
            bool changed = false;
            for (int i = 0;i < first.size(); i++) {
                if (first[i] != second[i]) {
                    if (changed)
                        return false;
                    changed = true;
                    // 不用真的改变
                }
            }
            return true;
        }
        else
            return false;
    }
};