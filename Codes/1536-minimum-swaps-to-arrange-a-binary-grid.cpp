/*
 * @Author: LetMeFly
 * @Date: 2026-03-02 09:24:27
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-03-02 09:32:18
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    inline int countSuffix(const vector<int>& row) {
        int ans = 0;
        for (int i = row.size() - 1; i >= 0; i--, ans++) {
            if (row[i] != 0) {
                break;
            }
        }
        return ans;
    }

    int change(vector<int>& suffix, int u, int d) {
        for (int i = d - 1; i >= u; i--) {
            swap(suffix[i], suffix[i + 1]);
        }
        return d - u;
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
                    ans += change(suffix, i, j);
                    goto loop;
                }
            }
            return -1;
            loop:;
        }
        return ans;
    }
};