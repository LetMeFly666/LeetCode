/*
 * @Author: LetMeFly
 * @Date: 2024-05-09 15:18:15
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-05-09 15:37:07
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int minimumRefill(vector<int>& plants, int capacityA, int capacityB) {
        int ans = 0;
        int nowA = capacityA, nowB = capacityB;
        for (int l = 0, r = plants.size() - 1; l <= r; l++, r--) {
            if (l == r) {
                if (max(nowA, nowB) < plants[l]) {
                    ans++;
                }
                break;
            }
            if (nowA < plants[l]) {
                ans++;
                nowA = capacityA;
            }
            nowA -= plants[l];
            if (nowB < plants[r]) {
                ans++;
                nowB = capacityB;
            }
            nowB -= plants[r];
        }
        return ans;
    }
};