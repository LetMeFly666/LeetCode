/*
 * @Author: LetMeFly
 * @Date: 2024-11-20 12:11:48
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2024-11-20 12:56:12
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

/*
每个点记录“自己跃迁到的点”
初始值每个点能跃迁到的点都是自己的下一个节点

新来一条“跃迁通道”有两种可能：
    + 被一条更长(或等长)的跃迁通道覆盖
    + 覆盖n条跃迁通道
反正不可能和其他跃迁通道有交叉
两种情况的判断方式是“跃迁起点”指向的“能跃迁到的点”是否大于(等于)自己的“跃迁终点”
    + 对于第一种情况：直接continue
    + 对于第二种情况：修改所有“最大被覆盖子跃迁通道”的起点的“能跃迁到的点”
*/
#ifdef TirstTry  // WA
class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<int> transitionTo(n);
        for (int i = 0; i < n; i++) {
            transitionTo[i] = i + 1;
        }
        int transitionToEndTimes = n - 1;
        vector<int> ans(queries.size());
        for (int i = 0; i < queries.size(); i++) {
            int from = queries[i][0], to = queries[i][1];
            while (transitionTo[from] < to) {
                int originalTo = transitionTo[from];
                transitionToEndTimes -= originalTo - from;
                transitionTo[from] = to;
                from = originalTo;
            }
            ans[i] = transitionToEndTimes;
        }
        return ans;
    }
};
#else  // TirstTry
#ifdef SecondTry  // WA
class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<int> transitionTo(n);
        for (int i = 0; i < n; i++) {
            transitionTo[i] = i + 1;
        }
        int transitionToEndTimes = n - 1;
        vector<int> ans(queries.size());
        for (int i = 0; i < queries.size(); i++) {
            int from = queries[i][0], to = queries[i][1];
            int originalJumpTimes = 0;
            while (transitionTo[from] <= to) {
                originalJumpTimes++;
                int originalTo = transitionTo[from];
                transitionTo[from] = to;
                from = originalTo;
            }
            transitionToEndTimes -= originalJumpTimes - 1;
            ans[i] = transitionToEndTimes;
        }
        return ans;
    }
};
#else  // SecondTry
#ifdef ThirdTry  // AC
class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<int> transitionTo(n);
        for (int i = 0; i < n; i++) {
            transitionTo[i] = i + 1;
        }
        int transitionToEndTimes = n - 1;
        vector<int> ans(queries.size());
        for (int i = 0; i < queries.size(); i++) {
            int from = queries[i][0], to = queries[i][1];
            int originalJumpTimes = 0;
            while (transitionTo[from] <= to) {
                originalJumpTimes++;
                int originalTo = transitionTo[from];
                transitionTo[from] = to;
                from = originalTo;
            }
            transitionToEndTimes -= max(0, originalJumpTimes - 1);
            ans[i] = transitionToEndTimes;
        }
        return ans;
    }
};
#else  // ThirdTry
// FourthTry  // 简化版  // 执行用时分布:2ms,击败98.51%;消耗内存分布:108.84MB,击败83.86%.
class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<int> transitionTo(n), ans(queries.size());
        for (int i = 0; i < n; i++) {
            transitionTo[i] = i + 1;
        }
        int transitionToEndTimes = n - 1;
        for (int i = 0; i < queries.size(); i++) {
            int from = queries[i][0], to = queries[i][1], now = from;
            while (transitionTo[now] < to) {
                transitionToEndTimes--;
                int originalTo = transitionTo[now];
                transitionTo[now] = to;
                now = originalTo;
            }
            ans[i] = transitionToEndTimes;
        }
        return ans;
    }
};
#endif  // ThirdTry
#endif  // SecondTry
#endif  // TirstTry