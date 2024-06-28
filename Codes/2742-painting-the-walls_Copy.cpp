/*
 * @Author: LetMeFly
 * @Date: 2024-06-28 10:13:05
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-06-28 13:02:30
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

/*
【C++】滚动 dp，我感觉这个方法比官方题解好理解一点

首先本题的time可以看做是额外刷t面墙，实际上就是cost的价格刷t+1面墙。

第 i 轮的 dp[j] 表示截止到第 i 个人，粉刷 j 面墙所需的价格

可以得到初步的递推

for(int k = max(0, j - 1 - t); k <= j; ++k) {
    dp[j] = min(dp[j], dp[k] + c);
}
显然根据定义，dp是单调增的，如果选取第i个人，只需要看刷t+1面墙以前的情况即可

因此有状态转移 dp[j] = min(dp[j], dp[max(0, j - 1 - t)] + c);

class Solution {
public:
    int paintWalls(vector<int>& cost, vector<int>& time) {
        int n = cost.size(), dp[n+1];
        memset(dp, 0x3f, sizeof dp);
        dp[0] = 0;
        for(int i = 0; i < n; ++i) {
            int c = cost[i], t = time[i];
            for(int j = n; j > 0; --j){
                dp[j] = min(dp[j], dp[max(0, j - 1 - t)] + c);
            }
        }
        return dp[n];
    }
};
*/

class Solution {
public:
    int paintWalls(vector<int>& cost, vector<int>& time) {
        vector<int> dp(cost.size() + 1, 1e8);  // dp[i]: 刷 
        
    }
};