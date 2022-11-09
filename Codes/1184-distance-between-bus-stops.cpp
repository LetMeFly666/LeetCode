/*
 * @Author: LetMeFly
 * @Date: 2022-07-24 11:13:34
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-07-24 11:15:51
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        if (start > destination) swap(start, destination);
        int s1 = 0;
        for (int i = start; i < destination; i++) {
            s1 += distance[i];
        }
        int s = 0;
        for (int i = 0; i < distance.size(); i++) {
            s += distance[i];
        }
        return min(s1, s - s1);
    }
};