/*
 * @Author: LetMeFly
 * @Date: 2025-09-28 19:37:00
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-09-28 20:07:49
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
/*
这个解决方案使用了三维动态规划：

dp[i][j][k] 表示学习了前i门课程，当前在第j层，总花费为k时能够获得的最大能力值
状态转移时，对于每个可能的状态，考虑下一门课程可以在任意楼层学习
计算课程花费时需要考虑楼层加成系数
计算楼层切换代价时，只有从低层到高层才需要支付代价
算法的时间复杂度是 O(n × m² × M)，在给定的约束条件下（n ≤ 100, m ≤ 5, M ≤ 1000）是可行的
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, M;
    cin >> n >> m >> M; 
    vector<int> power(n), cost(n), bonus(m);
    for (int i = 0; i < n; i++) cin >> power[i];
    for (int i = 0; i < n; i++) cin >> cost[i];
    for (int i = 0; i < m; i++) cin >> bonus[i];
    
    // dp[i][j][k]: 前i门课程，当前在第j层，总花费为k时的最大能力值
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(m, vector<int>(M + 1, -1)));
    for (int j = 0; j < m; j++) {
        dp[0][j][0] = 0;
    }
    
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k <= M; k++) {
                if (dp[i][j][k] == -1) {
                    continue;
                }
                for (int next_j = 0; next_j < m; next_j++) {
                    int course_cost = cost[i] * bonus[next_j];
                    int course_power = power[i] * bonus[next_j];
                    int switch_cost = 0;
                    if (next_j > j) { // 从低层切换到高层
                        switch_cost = next_j - j;
                    }
                    int total_cost = k + course_cost + switch_cost;
                    if (total_cost <= M) {
                        dp[i + 1][next_j][total_cost] = max(
                            dp[i + 1][next_j][total_cost],
                            dp[i][j][k] + course_power
                        );
                        ans = max(ans, dp[i + 1][next_j][total_cost]);
                    }
                }
            }
        }
    }
    
    cout << ans << endl;
    return 0;
}