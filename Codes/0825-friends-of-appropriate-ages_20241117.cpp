/*
 * @Author: LetMeFly
 * @Date: 2024-11-17 17:39:44
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2024-11-17 18:11:18
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

/*
对于x：x要加：
0.5x+7 < y <= x
x + 7 < 2y
也就是说
0.5x+7 < x 可得 x>14 才能有朋友
*/
#ifdef FirstTry  // WA: 同龄人会相互申请
class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        int ans = 0;
        sort(ages.begin(), ages.end());
        int l = 0;
        while (l < ages.size() && ages[l] <= 14) {
            l++;
        }
        for (int r = l + 1; r < ages.size(); r++) {
            while (ages[l] * 2 <= ages[r] + 7) {
                l++;
            }
            ans += r - l;
        }
        return ans;
    }
};
#else  // FirstTry
#ifdef SecondTry  // WA
class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        int ans = 0;
        sort(ages.begin(), ages.end());
        int y_l = 0;
        while (y_l < ages.size() && ages[y_l] <= 14) {
            y_l++;
        }
        for (int y_r = y_l, x = y_l; x < ages.size(); x++, y_r = max(y_r, x)) {
            while (ages[y_l] * 2 <= ages[x] + 7) {
                y_l++;
            }
            while (y_r + 1 < ages.size() && ages[y_r] == ages[y_r + 1]) {
                y_r++;
            }
            printf("y: [%d, %d], x: %d\n", y_l, y_r, x);  //*************
            ans += y_r - y_l;
        }
        return ans;
    }
};
#else  // SecondTry
// ThirdTry
class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        int ans = 0;
        sort(ages.begin(), ages.end());
        int y_l = 0;
        while (y_l < ages.size() && ages[y_l] <= 14) {
            y_l++;
        }
        for (int y_r = y_l, x = y_l; x < ages.size(); x++) {
            while (ages[y_l] * 2 <= ages[x] + 14) {
                y_l++;
            }
            while (y_r + 1 < ages.size() && ages[y_r + 1] <= ages[x]) {
                y_r++;
            }
            ans += y_r - y_l;
        }
        return ans;
    }
};
#endif  // SecondTry
#endif  // FirstTry