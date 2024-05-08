/*
 * @Author: LetMeFly
 * @Date: 2024-05-08 18:05:57
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-05-08 18:11:11
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        int step = 0;
        int now = capacity;
        for (int i = 0; i < plants.size(); i++) {
            if (now < plants[i]) {  // 上一步应该返回
                step += i + i;
                now = capacity;
            }
            step++;
            now -= plants[i];
        }
        return step;
    }
};