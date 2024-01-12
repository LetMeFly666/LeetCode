/*
 * @Author: LetMeFly
 * @Date: 2024-01-12 19:04:59
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-01-12 19:06:15
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        unordered_map<string, int> m1, m2;
        for (auto& s : words1) {
            m1[s]++;
        }
        for (auto& s : words2) {
            m2[s]++;
        }
        int ans = 0;
        for (auto&& [str, cnt] : m1) {
            if (m2[str] == 1) {
                ans++;
            }
        }
        return ans;
    }
};