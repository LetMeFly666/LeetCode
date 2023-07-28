/*
 * @Author: LetMeFly
 * @Date: 2023-07-28 08:39:29
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-07-28 08:53:18
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    vector<vector<int>> pre;
    vector<int> dp;
    vector<int> time;

    int dfs(int n) {  // n从0开始
        if (dp[n]) {
            return dp[n];
        }
        for (int thisPre : pre[n]) {
            // printf("n = %d, thisPre = %d, max(%d", n, thisPre, dp[n]);  //******
            dp[n] = max(dp[n], dfs(thisPre));
            // printf(", %d) = %d\n", dfs(thisPre), dp[n]);  //*********
        }
        return (dp[n] += time[n]);
    }
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        this->time = time;
        pre.resize(n);
        dp.resize(n);
        for (vector<int>& relation : relations) {
            pre[relation[1] - 1].push_back(relation[0] - 1);
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans = max(ans, dfs(i));
        }
        return ans;
    }
};