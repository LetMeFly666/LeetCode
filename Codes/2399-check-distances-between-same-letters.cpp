/*
 * @Author: LetMeFly
 * @Date: 2023-04-09 09:43:42
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-04-09 09:46:24
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    bool checkDistances(string s, vector<int>& distance) {
        for (int i = 0; i < s.size(); i++) {
            if (distance[s[i] - 'a'] != -1) {
                int should = i + distance[s[i] - 'a'] + 1;
                if (should >= s.size() || s[should] != s[i]) {
                    return false;
                }
                distance[s[i] - 'a'] = -1;
            }
        }
        return true;
    }
};