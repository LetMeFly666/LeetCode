/*
 * @Author: LetMeFly
 * @Date: 2025-09-02 13:08:07
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-09-02 13:45:45
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    inline bool check(vector<vector<int>>& points, int i, int j) {  // 易错点3：单独的(i, j)也要check
        if (points[i][0] > points[j][0] || points[i][1] < points[j][1]) {  // 易错点1：注意这里纵坐标大于等于才合法
            return false;
        }
        return true;
    }
    inline bool check(vector<vector<int>>& points, int i, int j, int k) {
        if (points[i][0] <= points[k][0] && points[k][0] <= points[j][0] && points[i][1] >= points[k][1] && points[k][1] >= points[j][1]) {
            return false;
        }
        return true;
    }
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int ans = 0;
        for (int i = 0; i < points.size(); i++) {
            for (int j = 0; j < points.size(); j++) {
                if (i == j) {
                    continue;
                }
                if (!check(points, i, j)) {
                    continue;
                }
                bool can = true;  // 易错点2：有一个k导致不符就不符
                for (int k = 0; k < points.size(); k++) {
                    if (k == i || k == j) {
                        continue;
                    }
                    if (!check(points, i, j, k)) {
                        can = false;
                        break;
                    }
                }
                ans += can;
            }
        }
        return ans;
    }
};

#if defined(_WIN32) || defined(__APPLE__)
/*
[[1,1],[2,2],[3,3]]

0
*/
/*
[[0,0],[0,3]]

1
*/
/*
[[6,2],[4,4],[2,6]]

(2,1) (1, 0)

2
*/
/*
[[0,0],[0,3]]

1
*/
int main() {
    string s;
    while (cin >> s) {
        vector<vector<int>> v = stringToVectorVector(s);
        Solution sol;
        cout << sol.numberOfPairs(v) << endl;
    }
    return 0;
}
#endif