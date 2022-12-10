/*
 * @Author: LetMeFly
 * @Date: 2022-12-10 10:09:39
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-12-10 10:44:40
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

// Copy from https://leetcode.cn/problems/maximum-height-by-stacking-cuboids/solutions/2014514/tu-jie-suan-fa-you-hua-xiang-xi-zheng-mi-b6fq/
class Solution {
public:
    int maxHeight(vector<vector<int>> &cuboids) {
        for (auto &c : cuboids)
            sort(c.begin(), c.end());
        sort(cuboids.begin(), cuboids.end());
        int n = cuboids.size(), f[n];
        for (int i = 0; i < n; ++i) {
            f[i] = 0;
            for (int j = 0; j < i; ++j)
                // 排序后，cuboids[j][0] <= cuboids[i][0] 恒成立
                if (cuboids[j][1] <= cuboids[i][1] && cuboids[j][2] <= cuboids[i][2])
                    f[i] = max(f[i], f[j]); // cuboids[j] 可以堆在 cuboids[i] 上
            f[i] += cuboids[i][2];
        }
        return *max_element(f, f + n);
    }
};