/*
 * @Author: LetMeFly
 * @Date: 2022-05-08 09:56:28
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-05-08 09:59:11
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0, r = height.size() - 1;
        int ans = 0;
        while (l < r) {
            ans = max(ans, min(height[r], height[l]) * (r - l));
            if (height[l] < height[r])
                l++;
            else
                r--;
        }
        return ans;
    }
};