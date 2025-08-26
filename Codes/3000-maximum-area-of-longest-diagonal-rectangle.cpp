/*
 * @Author: LetMeFly
 * @Date: 2025-08-26 21:25:10
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-08-26 21:32:11
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int ans = 0;
        int M = 0;
        for (vector<int>& d : dimensions) {
            int l2 = d[0] * d[0] + d[1] * d[1];
            if (l2 > M) {
                M = l2;
                ans = d[0] * d[1];
            } else if (l2 == M) {
                ans = max(ans, d[0] * d[1]);
            }
        }
        return ans;
    }
};

#if defined(_WIN32) || defined(__APPLE__)
/*
[[6,5],[8,6],[2,10],[8,1],[9,2],[3,5],[3,5]]
*/
int main() {
    string s;
    while (cin >> s) {
        vector<vector<int>> v = stringToVectorVector(s);
        Solution sol;
        cout << sol.areaOfMaxDiagonal(v) << endl;
    }
    return 0;
}
#endif