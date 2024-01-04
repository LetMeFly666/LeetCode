/*
 * @Author: LetMeFly
 * @Date: 2024-01-04 20:58:56
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-01-04 21:12:34
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int maximumRows(vector<vector<int>>& matrix, int numSelect) {
        int ans = 0;
        int m = matrix.size(), n = matrix[0].size();
        for (int state = 0; state < (1 << n); state++) {
            if (__builtin_popcount(state) != numSelect) {
                continue;
            }
            int thisAns = 0;
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (matrix[i][j] && !(state & (1 << j))) {
                        goto loop;
                    }
                }
                thisAns++;
                loop:;
            }
            ans = max(ans, thisAns);
        }
        return ans;
    }
};


#ifdef _WIN32
/*
[[0,0,1],[1,0,0],[0,0,0]]
2

001
100
000
*/
int main() {
    string s;
    int t;
    while (cin >> s >> t) {
        vector<vector<int>> v = stringToVectorVector(s);
        Solution sol;
        cout << sol.maximumRows(v, t) << endl;
    }
    return 0;
}
#endif