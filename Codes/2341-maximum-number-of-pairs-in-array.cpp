/*
 * @Author: LetMeFly
 * @Date: 2023-02-16 09:21:49
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-02-16 09:31:26
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        unordered_set<int> se;
        int cntPair = 0;
        for (int& t : nums) {
            if (se.count(t)) {
                se.erase(t);
                cntPair++;
            }
            else {
                se.insert(t);
            }
        }
        return {cntPair, (int)nums.size() - cntPair * 2};
    }
};