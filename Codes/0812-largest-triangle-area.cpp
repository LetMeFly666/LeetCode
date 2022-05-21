/*
 * @Author: LetMeFly
 * @Date: 2022-05-15 08:10:27
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-05-15 08:22:26
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#else
#define dbg(x) cout << #x << " : " << x << endl
#endif

#define getLength(i, j) sqrt((points[i][0] - points[j][0]) * (points[i][0] - points[j][0]) + (points[i][1] - points[j][1]) * (points[i][1] - points[j][1]))

double getArea(vector<vector<int>>& points, int i, int j, int k) {
    // if (points[i][0] == points[j][0] && points[i][0] == points[k][0])
    //     return 0;
    // if (points[i][1] == points[j][1] && points[i][1] == points[k][1])
    //     return 0;
    double a = getLength(i, j);
    // dbg(a);
    // dbg(getLength(i, j));
    double b = getLength(j, k);
    double c = getLength(i, k);
    double p = (a + b + c) / 2;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}

class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        double ans = 0;
        int n = points.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                for (int k = j + 1; k < n; k++) {
                    ans = max(ans, getArea(points, i, j, k));
                }
            }
        }
        return ans;
    }
};