/*
 * @Author: LetMeFly
 * @Date: 2024-02-28 21:05:29
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-02-28 21:12:38
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

/*
   0
 1   2
3 4 5 6
*/

class Solution {
private:
    int ans;

    int dfs(int n, vector<int>& cost) {
        if (n >= cost.size()) {
            return 0;
        }
        int leftSum = dfs(n * 2 + 1, cost);
        int rightSum = dfs(n * 2 + 2, cost);
        ans += max(leftSum, rightSum) - min(leftSum, rightSum);
        return max(leftSum, rightSum) + cost[n];
    }
public:
    int minIncrements(int n, vector<int>& cost) {
        ans = 0;
        dfs(0, cost);
        return ans;
    }
};