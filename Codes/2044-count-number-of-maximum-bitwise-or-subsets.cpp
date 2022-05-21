/*
 * @Author: LetMeFly
 * @Date: 2022-03-15 08:50:11
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-03-15 08:55:40
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    int M = 0, ans = 0;

    void dfs(int pos, int val, vector<int>& a) {
        if (pos >= a.size()) {
            if (val > M) {
                M = val;
                ans = 1;
            }
            else if (val == M) {
                ans++;
            }
            return ;
        }
        dfs(pos + 1, val, a);
        // 不可这么剪，否则cnt可能偏少
        // if ((val | a[pos]) != val)  // 剪枝
            // dfs(pos + 1, val | a[pos], a);
        dfs(pos + 1, val | a[pos], a);
    }

public:
    int countMaxOrSubsets(vector<int>& nums) {
        dfs(0, 0, nums);
        return ans;
    }
};