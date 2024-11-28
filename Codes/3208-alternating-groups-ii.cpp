/*
 * @Author: LetMeFly
 * @Date: 2024-11-28 23:26:43
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2024-11-28 23:29:44
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int ans = 0;
        int cntDiff = 0;
        for (int i = 1; i < k; i++) {
            if (colors[i] != colors[i - 1]) {
                cntDiff++;
            }
        }
        for (int i = 0; i < colors.size(); i++) {
            ans += cntDiff == k - 1;
            cntDiff += colors[(i + k) % colors.size()] != colors[(i + k - 1) % colors.size()];
            cntDiff -= colors[(i + 1) % colors.size()] != colors[i];
        }
        return ans;
    }
};