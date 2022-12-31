/*
 * @Author: LetMeFly
 * @Date: 2022-12-31 09:52:11
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-12-31 09:53:22
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        sort(seats.begin(), seats.end());
        sort(students.begin(), students.end());
        int ans = 0;
        for (int i = 0; i < seats.size(); i++) {
            ans += abs(seats[i] - students[i]);
        }
        return ans;
    }
};