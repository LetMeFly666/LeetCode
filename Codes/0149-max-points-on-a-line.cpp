/*
 * @Author: LetMeFly
 * @Date: 2022-07-31 11:09:16
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-07-31 12:11:37
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

long double ONE = 1;

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int ans = 0;
        int n = points.size();
        
        for (int i = 0; i < n; i++) {
            unordered_map<long double, int> ma;
            int thisAns = 0;
            for (int j = 0 ; j < n; j++) {
                if (i == j)
                    continue;
                long double k = ONE * (points[j][1] - points[i][1]) / (points[j][0] - points[i][0]);
                ma[k]++;
                thisAns = max(thisAns, ma[k]);
            }
            ans = max(ans, thisAns + 1);
        }

        return ans;
    }
};