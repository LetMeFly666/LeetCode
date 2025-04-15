/*
 * @Author: LetMeFly
 * @Date: 2025-04-15 10:24:13
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-04-15 10:28:19
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        int ans = 0, n = arr.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (abs(arr[i] - arr[j]) > a) {
                    continue;
                }
                for (int k = j + 1; k < n; k++) {
                    ans += abs(arr[j] - arr[k]) <= b && abs(arr[i] - arr[k]) <= c;
                }
            }
        }
        return ans;
    }
};