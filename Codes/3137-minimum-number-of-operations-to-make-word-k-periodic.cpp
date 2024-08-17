/*
 * @Author: LetMeFly
 * @Date: 2024-08-17 12:45:06
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-08-17 12:46:16
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int minimumOperationsToMakeKPeriodic(string& word, int k) {
        unordered_map<string, int> ma;
        int maxTimes = 1;
        for (int i = 0; i < word.size(); i += k) {
            maxTimes = max(maxTimes, ++ma[word.substr(i, k)]);
        }
        return word.size() / k - maxTimes;
    }
};