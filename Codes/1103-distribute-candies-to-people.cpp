/*
 * @Author: LetMeFly
 * @Date: 2024-06-03 14:56:17
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-06-03 14:58:12
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> ans(num_people);
        int num = 1, index = 0;
        while (candies) {
            int thisTime = min(num, candies);
            num++;
            candies -= thisTime;
            ans[index] += thisTime;
            index = (index + 1) % num_people;
        }
        return ans;
    }
};