/*
 * @Author: LetMeFly
 * @Date: 2022-09-05 16:44:03
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-09-05 16:48:52
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int minimumRefill(vector<int>& plants, int capacityA, int capacityB) {
        int nowA = capacityA, nowB = capacityB;
        int ans = 0;
        int l = 0, r = plants.size() - 1;
        while (l < r) {
            if (nowA < plants[l]) {
                nowA = capacityA;
                ans++;
            }
            if (nowB < plants[r]) {
                nowB = capacityB;
                ans++;
            }
            nowA -= plants[l++];
            nowB -= plants[r--];
        }
        if (l == r) {
            if (max(nowA, nowB) < plants[l]) {
                ans++;
                // 未更新水容量
            }
        }
        return ans;
    }
};