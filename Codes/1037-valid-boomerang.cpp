/*
 * @Author: LetMeFly
 * @Date: 2022-06-08 10:15:36
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-06-08 10:25:31
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

#ifdef FirstTry
class Solution {
public:
    bool isBoomerang(vector<vector<int>>& points) {
        if (points[0][0] == points[1][0] && points[1][0] == points[2][0])
            return false;
        if (points[0][1] == points[1][1] && points[1][1] == points[2][1])
            return false;
        if ((points[0][0] - points[1][0]) * (points[1][1] - points[2][1]) == (points[1][0] - points[2][0]) * (points[0][1] - points[1][1]))
            return false;
        return true;
    }
};
#else  // FirstTry
// SecondTry：精简版
class Solution {
public:
    bool isBoomerang(vector<vector<int>>& points) {
        return (points[0][0] - points[1][0]) * (points[1][1] - points[2][1]) != (points[1][0] - points[2][0]) * (points[0][1] - points[1][1]);
    }
};
#endif  // FirstTry