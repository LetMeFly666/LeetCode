/*
 * @Author: LetMeFly
 * @Date: 2024-10-22 18:32:19
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-10-22 18:35:23
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

#ifdef FirstTry  // WA: 算重复了
class Solution {
public:
    int countCompleteDayPairs(vector<int>& hours) {
        int ans = 0;
        for (int x : hours) {
            for (int y : hours) {
                ans += ((x + y) % 24 == 0);
            }
        }
        return ans;
    }
};
#else  // FirstTry
// SecondTry
class Solution {
public:
    int countCompleteDayPairs(vector<int>& hours) {
        int ans = 0;
        for (int i = 0; i < hours.size(); i++) {
            for (int j = i + 1; j < hours.size(); j++) {
                ans += (hours[i] + hours[j]) % 24 == 0;
            }
        }
        return ans;
    }
};
#endif  // FirstTry