/*
 * @Author: LetMeFly
 * @Date: 2024-06-10 15:13:13
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-06-10 15:15:40
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int ans = 0;
        for (int l = 0, r = people.size() - 1; l <= r;) {
            if (people[l] + people[r] <= limit) {  // 不用特判l是否等于r
                l++, r--;
            }
            else {
                r--;
            }
            ans++;
        }
        return ans;
    }
};