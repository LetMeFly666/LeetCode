/*
 * @Author: LetMeFly
 * @Date: 2026-03-02 09:24:27
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-03-02 09:28:47
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    inline int countSuffix(vector<int>& row) {
        int ans = 0;
        for (int i = row.size() - 1; i >= 0; i--, ans++) {
            if (row[i] != 0) {
                break;
            }
        }
        return ans;
    }
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> suffix(n);
        for (int i = 0; i < n; i++) {
            suffix[i] = countSuffix(grid[i]);
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (suffix[j] >= n - i - 1) {
                    swap(suffix[i], suffix[j]);
                    ans += j - i;
                    goto loop;
                }
            }
            return -1;
            loop:;
        }
        return ans;
    }
};