/*
 * @Author: LetMeFly
 * @Date: 2023-02-24 08:48:44
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-02-24 08:48:44
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_set<int> se;
        for (int& t : nums) {
            if (t) {
                se.insert(t);
            }
        }
        return se.size();
    }
};