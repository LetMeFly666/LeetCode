/*
 * @Author: LetMeFly
 * @Date: 2022-06-13 10:12:07
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-06-13 10:13:12
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> original = heights;
        sort(heights.begin(), heights.end());
        int ans = 0;
        for (int i = 0; i < original.size(); i++) {
            ans += original[i] != heights[i];
        }
        return ans;
    }
};