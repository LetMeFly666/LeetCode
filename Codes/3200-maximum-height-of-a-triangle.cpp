/*
 * @Author: LetMeFly
 * @Date: 2024-10-15 20:03:46
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-10-15 23:45:00
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int maxHeightOfTriangle(int red, int blue) {
        int cnt[2] = {0, 0};
        int layer = 1;
        while (true) {
            cnt[layer % 2] += layer++;
            // printf("cnt = [%d, %d]\n", cnt[0], cnt[1]);  //*********
            // printf("cnt[0] = %d, red = %d, cnt[1] = %d, blud = %d\n", cnt[0], red, cnt[1], blue);  //********
            if (!((cnt[0] <= red && cnt[1] <= blue) || (cnt[0] <= blue && cnt[1] <= red))) {
                return layer - 2;
            }
        }
    }
};