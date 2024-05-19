/*
 * @Author: LetMeFly
 * @Date: 2024-05-19 11:06:27
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-05-19 11:07:42
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int winner = arr[0], winTime = 0;
        for (int i = 1; i < arr.size(); i++) {
            if (winner > arr[i]) {
                winTime++;
            }
            else {
                winner = arr[i];
                winTime = 1;
            }
            if (winTime == k) {
                return winner;
            }
        }
        return winner;
    }
};