/*
 * @Author: LetMeFly
 * @Date: 2022-06-14 15:04:55
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-06-14 15:16:23
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int> ans;
        int n = mat.size(), m = mat[0].size();
        int x = 0, y = 0;
        bool direction = true;
        while (true) {
            ans.push_back(mat[x][y]);
            if (x == n - 1 && y == m - 1)
                break;
            if (direction) {  // ↗
                if (y == m - 1) {
                    x++;
                    direction = false;
                }
                else if (x == 0) {
                    y++;
                    direction = false;
                }
                else {
                    x--, y++;
                }
            }
            else {  // ↙
                if (x == n - 1) {
                    y++;
                    direction = true;
                }
                else if (y == 0) {
                    x++;
                    direction = true;
                }
                else {
                    x++, y--;
                }
            }
        }
        return ans;
    }
};