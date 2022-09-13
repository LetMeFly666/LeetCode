/*
 * @Author: LetMeFly
 * @Date: 2022-09-13 08:19:26
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-09-13 08:24:09
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        for (int i = 0; i < s.size(); i++) {
            int locM = -1;
            char M = 0;
            for (int j = i + 1; j < s.size(); j++) {
                if (s[j] > s[i] && s[j] >= M) {
                    locM = j, M = s[j];
                }
            }
            if (locM != -1) {
                swap(s[i], s[locM]);
                return atoi(s.c_str());
            }
        }
        return atoi(s.c_str());
    }
};