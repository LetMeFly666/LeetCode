/*
 * @Author: LetMeFly
 * @Date: 2024-12-19 15:53:21
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2024-12-19 15:53:31
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    vector<int> stableMountains(vector<int>& height, int threshold) {
        vector<int> ans;
        for (int i = 1; i < height.size(); i++) {
            if (height[i - 1] > threshold) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};