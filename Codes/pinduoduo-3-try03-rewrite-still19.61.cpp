/*
 * @Author: LetMeFly
 * @Date: 2025-09-28 19:37:00
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-09-28 19:59:46
 */
/*
共有n门课程，每个课程有两个属性：
1. power：学习后可以提升的能力值
2. cost：学习这门课程需要的代价
学院共有m层楼，每层有不同的环境加成系数bonus[j]（1<=bouns[j]<=3）
多多总共有M点初始金币，学习规则如下：
1. 必须按顺序学习课程
2. 一门课只能在一层完成，不能跨层
3. 在第j层学习第i门课程时，需要消耗cost[i] * bonus[j]的金币
4. 在第j层学习第i门课程后，会提升power[i] * bonus[j]的能力值
5. 多多可以在楼层间切换，第一次选择楼层没有代价，每次切换时：若从低层切换到高层，消耗楼层高度差到代价（如从第1层切换到第3层，消耗2的代价）；若从高层切换到低层，则不消化代价。
请求出总消耗不超过M的前提下最大能力值提升

输入：
第一行三个整数n m M (1 <= n <= 100, 1 <= m <= 5, 1 <= M <= 1000)
第二行n个整数power[i] (1 <= power[i] <= 100)
第三行n个整数cost[i] (1 <= cost[i] <= 100)
第四行m个整数bonus[j] (1 <= bonus[j] <= 3)

输出：一个整数代表可以提升的最大能力值
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, M;
    cin >> n >> m >> M;
    
    vector<int> power(n), cost(n), bonus(m);
    for (auto& p : power) cin >> p;
    for (auto& c : cost) cin >> c;
    for (auto& b : bonus) cin >> b;
    
    // dp[i][j][c] = 前i门课，当前在j层，总消耗c的最大能力
    vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(m, vector<int>(M+1, -1)));
    
    // 初始化：处理0门课时所有楼层消耗为0
    for (int j = 0; j < m; j++) {
        dp[0][j][0] = 0;
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < m; j++) {
            int cur_cost = cost[i-1] * bonus[j];
            int cur_power = power[i-1] * bonus[j];
            
            for (int k = 0; k < m; k++) { // 前一次所在的楼层
                for (int c = 0; c <= M; c++) {
                    if (dp[i-1][k][c] == -1) continue;
                    
                    // 计算楼层切换代价
                    int switch_cost = (i == 1) ? 0 : max(j - k, 0);
                    int total_cost = c + cur_cost + switch_cost;
                    
                    if (total_cost > M) continue;
                    
                    dp[i][j][total_cost] = max(dp[i][j][total_cost], 
                                              dp[i-1][k][c] + cur_power);
                }
            }
        }
    }
    
    int ans = 0;
    for (int j = 0; j < m; j++)
        for (int c = 0; c <= M; c++)
            ans = max(ans, dp[n][j][c]);
    
    cout << ans << endl;
    return 0;
}