/*
 * @Author: LetMeFly
 * @Date: 2024-06-02 09:38:52
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-06-02 09:40:13
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        set<int> se(candyType.begin(), candyType.end());
        return min(se.size(), candyType.size() / 2);
    }
};