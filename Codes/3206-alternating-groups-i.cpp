/*
 * @Author: LetMeFly
 * @Date: 2024-11-26 23:18:14
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2024-11-26 23:18:20
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors) {
        int ans = 0;
        for (int i = 0; i < colors.size(); i++) {
            if (colors[i] != colors[(i + 1) % colors.size()] && colors[i] == colors[(i + 2) % colors.size()]) {
                ans++;
            }
        }
        return ans;
    }
};