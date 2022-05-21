/*
 * @Author: LetMeFly
 * @Date: 2021-10-25 15:51:57
 * @LastEditors: LetMeFly
 * @LastEditTime: 2021-10-25 15:56:34
 */
#include <bits/stdc++.h>
using namespace std;
#define mem(a) memset(a, 0, sizeof(a))
#define dbg(x) cout << #x << " = " << x << endl
#define fi(i, l, r) for (int i = l; i < r; i++)
#define cd(a) scanf("%d", &a)
typedef long long ll;

/* 直接 */
// class Solution {
// public:
//     bool searchMatrix(vector<vector<int>> &matrix, int target) {
//         for (vector<int> &v : matrix) {
//             for (int &t : v) {
//                 if (target == t) {
//                     return true;
//                 }
//             }
//         }
//         return false;
//     }
// };

/* 行二分 */
// class Solution {
// public:
//     bool searchMatrix(vector<vector<int>>& matrix, int target) {
//         for (const auto& row: matrix) {
//             auto it = lower_bound(row.begin(), row.end(), target);
//             if (it != row.end() && *it == target) {
//                 return true;
//             }
//         }
//         return false;
//     }
// };

/* Z字形 */
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int x = 0, y = n - 1;
        while (x < m && y >= 0) {
            if (matrix[x][y] == target) {
                return true;
            }
            if (matrix[x][y] > target) {
                --y;
            }
            else {
                ++x;
            }
        }
        return false;
    }
};