/*
 * @Author: LetMeFly
 * @Date: 2026-01-02 13:18:26
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-01-02 13:20:38
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_set<int> visited;
        for (int t : nums) {
            if (visited.count(t)) {
                return t;
            }
            visited.insert(t);
        }
        return -1;  // FAKE RETURN
    }
};