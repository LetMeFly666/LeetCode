/*
 * @Author: LetMeFly
 * @Date: 2024-10-24 12:18:05
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-10-24 12:20:43
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int findWinningPlayer(vector<int>& skills, int k) {
        int maxLoc = 0;
        for (int curLoc = 1, cnt = 0; curLoc < skills.size() && cnt < k; curLoc++) {
            if (skills[maxLoc] > skills[curLoc]) {
                cnt++;
            } else {
                maxLoc = curLoc;
                cnt = 1;
            }
        }
        return maxLoc;
    }
};