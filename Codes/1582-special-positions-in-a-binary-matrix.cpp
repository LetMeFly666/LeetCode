/*
 * @Author: LetMeFly
 * @Date: 2022-09-04 14:29:19
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-09-04 14:57:17
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif
#define FirstTry
#ifdef FirstTry  
// 方法一：时间O(mn)，空间O(m + n)
class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int ans = 0;
        int n = mat.size(), m = mat[0].size();
        vector<int> row(n, 0), col(m, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                row[i] += mat[i][j];
                col[j] += mat[i][j];
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] && row[i] == 1 && col[j] == 1) {
                    ans++;
                }
            }
        }
        return ans;
    }
};
#else  // FirstTry
// SecondTry  // 方法二，时间O(mn(m+n))，空间O(1)
class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int ans = 0;
        int n = mat.size(), m = mat[0].size();
        function<bool(int, int)> ok = [&](int x, int y) {
            for (int i = 0; i < n; i++) {
                if (i == x)
                    continue;
                if (mat[i][y])
                    return false;
            }
            for (int j = 0; j < m; j++) {
                if (j == y)
                    continue;
                if (mat[x][j])
                    return false;
            }
            return true;
        };
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] && ok(i, j)) {
                    ans++;
                }
            }
        }
        return ans;
    }
};
#endif  // FirstTry

#ifdef _WIN32
int main() {
    string s;
    while (cin >> s) {
        Solution sol;
        vector<vector<int>> v = stringToVectorVector(s);
        cout << sol.numSpecial(v) << endl;
    }
    return 0;
}
#endif