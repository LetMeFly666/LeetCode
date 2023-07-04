/*
 * @Author: LetMeFly
 * @Date: 2023-07-05 07:30:48
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-07-05 07:32:11
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k) {
        int ans = 0;
        int a[3][2] = {{numOnes, 1}, {numZeros, 0}, {numNegOnes, -1}};
        for (int i = 0; i < 3; i++) {
            int thisNum = min(k, a[i][0]);
            ans += a[i][1] * thisNum;
            k -= thisNum;
        }
        return ans;
    }
};