/*
 * @Author: LetMeFly
 * @Date: 2022-09-14 13:33:46
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-09-14 13:35:23
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    double trimMean(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int cnt = 0;
        int from = arr.size() * 0.05, to = arr.size() * 0.95;
        for (int i = from; i < to; i++) {
            cnt += arr[i];
        }
        return ((double) cnt) / (arr.size() * 0.9);
    }
};