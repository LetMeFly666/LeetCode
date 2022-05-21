/*
 * @Author: LetMeFly
 * @Date: 2022-04-22 08:38:23
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-04-22 08:39:26
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> se;
        for (int& t : nums) {
            if (se.count(t))
                return true;
            se.insert(t);
        }
        return false;
    }
};