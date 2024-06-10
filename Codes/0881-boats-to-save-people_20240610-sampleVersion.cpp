/*
 * @Author: LetMeFly
 * @Date: 2024-06-10 15:16:16
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-06-10 15:17:50
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int ans = 0;
        for (int l = 0, r = people.size() - 1; l <= r; ans++, r--) {
            if (people[l] + people[r] <= limit) {
                l++;
            }
        }
        return ans;
    }
};