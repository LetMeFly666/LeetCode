/*
 * @Author: LetMeFly
 * @Date: 2025-09-28 19:37:00
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-09-28 19:54:20
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
这个问题可以用三维动态规划来解决：

定义状态：dp[i][j][k]表示学完前i门课程，当前在第j层，总消耗为k的情况下能获得的最大能力值。

初始化：初始状态下，没有学习任何课程，所以在任意楼层、消耗0金币时，能力值为0。

状态转移：对于每一个状态dp[i][j][k]，我们有两种选择：

继续在当前楼层j学习第i+1门课程
切换到其他楼层l后学习第i+1门课程（如果从低层切换到高层需要支付楼层高度差的代价）
最终结果：遍历所有学完n门课程的状态，找出消耗不超过M金币的最大能力值。

时间复杂度：O(n * m * M * m)，其中n是课程数，m是楼层数，M是初始金币数。由于题目限制n<=100, m<=5, M<=1000，这个算法的复杂度是可接受的。

空间复杂度：O(n * m * M)，主要是动态规划数组的空间消耗。
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, m, M;
    cin >> n >> m >> M;
    vector<int> power(n);
    for (int i = 0; i < n; i++) {
        cin >> power[i];
    }
    vector<int> cost(n);
    for (int i = 0; i < n; i++) {
        cin >> cost[i];
    }
    vector<int> bonus(m);
    for (int i = 0; i < m; i++) {
        cin >> bonus[i];
    }
    // dp[i][j][k] 表示学完前i门课程，当前在第j层，总消耗为k的情况下能获得的最大能力值
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(m, vector<int>(M + 1, -1)));
    for (int j = 0; j < m; j++) {
        dp[0][j][0] = 0;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k <= M; k++) {
                if (dp[i][j][k] == -1) {
                    continue;
                }
                // 选择继续在j层学习第i+1门课
                int newCost = k + cost[i] * bonus[j];
                int newPower = dp[i][j][k] + power[i] * bonus[j];
                if (newCost <= M && newPower > dp[i + 1][j][newCost]) {
                    dp[i + 1][j][newCost] = newPower;
                }
                // 选择切换到其他楼层l，然后学习第i+1门课
                for (int l = 0; l < m; l++) {
                    if (l == j) { 
                        continue;
                    }
                    int switchCost = 0;
                    if (l > j) {
                        switchCost = l - j;
                    }
                    newCost = k + switchCost + cost[i] * bonus[l];
                    newPower = dp[i][j][k] + power[i] * bonus[l];
                    if (newCost <= M && newPower > dp[i + 1][l][newCost]) {
                        dp[i + 1][l][newCost] = newPower;
                    }
                }
            }
        }
    }
    
    int maxPower = 0;
    for (int j = 0; j < m; j++) {
        for (int k = 0; k <= M; k++) {
            if (dp[n][j][k] != -1) {
                maxPower = max(maxPower, dp[n][j][k]);
            }
        }
    }
    cout << maxPower << endl;
    
    return 0;
}