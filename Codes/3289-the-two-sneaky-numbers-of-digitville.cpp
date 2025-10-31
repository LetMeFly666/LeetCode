/*
 * @Author: LetMeFly
 * @Date: 2025-10-31 22:19:33
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-10-31 22:19:51
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        unordered_set<int> se;
        vector<int> ans;
        for (int t : nums) {
            if (se.count(t)) {
                ans.push_back(t);
            } else {
                se.insert(t);
            }
        }
        return ans;
    }
};