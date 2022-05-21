/*
 * @Author: LetMeFly
 * @Date: 2022-03-27 09:52:11
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-03-27 09:56:42
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

// class Solution {
// public:
//     vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
//         int Sum = 0;
//         for (int &t : rolls) {
//             Sum += t;
//         }
//         int allNum = rolls.size() + n;
//         int Sum_m = allNum * mean;
//         int Sum_M = Sum_m + allNum - 1;
//         int need_m = Sum_m - Sum;
//         // 先不写了
//     }
// };

// LeetCode
class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        int sum = mean * (n + m);
        int missingSum = sum;
        for (int & roll : rolls) {
            missingSum -= roll;
        }
        if (missingSum < n || missingSum > 6 * n) {
            return {};
        }
        int quotient = missingSum / n, remainder = missingSum % n;
        vector<int> missing(n);
        for (int i = 0; i < n; i++) {
            missing[i] = quotient + (i < remainder ? 1 : 0);
        }
        return missing;
    }
};