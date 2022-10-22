/*
 * @Author: LetMeFly
 * @Date: 2022-10-22 09:02:31
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-10-22 10:19:56
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#else
#define dbg(x) cout << #x << " = " << x << endl
#endif

#ifdef FirstTry  // 离散化：多次哈希+DPx1
class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        unordered_set<int> appearedTimeSet;  // 所有的出现过的时间
        unordered_multimap<int, int> endBy;  // <在这个时间结束, 这个任务对应的编号>
        int n = startTime.size();
        for (int i = 0; i < n; i++) {
            appearedTimeSet.insert(startTime[i]);
            appearedTimeSet.insert(endTime[i]);
            endBy.insert({endTime[i], i});
        }
        vector<int> appearedTime;
        for (const int& t : appearedTimeSet) {
            appearedTime.push_back(t);
        }
        sort(appearedTime.begin(), appearedTime.end());
        int nTime = appearedTime.size();
        unordered_map<int, int> time2loc;
        for (int i = 0; i < nTime; i++) {
            time2loc[appearedTime[i]] = i;
        }
        vector<int> dp(nTime);
        for (int i = 1; i < nTime; i++) {
            dp[i] = dp[i - 1];
            auto range = endBy.equal_range(appearedTime[i]);
            for_each(range.first, range.second, [&](unordered_multimap<int, int>::value_type& x) {
                dp[i] = max(dp[i], dp[time2loc[startTime[x.second]]] + profit[x.second]);
            });
            printf("i = %d, appearedTime[%d] = %d, dp[%d] = %d\n", i, i, appearedTime[i], i, dp[i]);  //************
        }
        return dp.back();
    }
};
#else  // FirstTry
// SecondTry  // 二分查找 + DP  // https://leetcode.cn/problems/maximum-profit-in-job-scheduling/solution/gui-hua-jian-zhi-gong-zuo-by-leetcode-so-gu0e/
class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<vector<int>> jobs(n);
        for (int i = 0; i < n; i++) {
            jobs[i] = {startTime[i], endTime[i], profit[i]};
        }
        sort(jobs.begin(), jobs.end(), [&](const vector<int>& a, const vector<int>& b){
            return a[1] < b[1];
        });
        vector<int> dp(n + 1);
        for (int i = 1; i <= n; i++) {
            int k = upper_bound(jobs.begin(), jobs.begin() + i - 1, jobs[i - 1][0], [&](int st, vector<int>& job) {
                return st < job[1];
            }) - jobs.begin();
            dp[i] = max(dp[i - 1], dp[k] + jobs[i - 1][2]);
        }
        return dp[n];
    }
};
#endif  // FirstTry



#ifdef _WIN32

/*
[1,2,3,3]
[3,4,5,6]
[50,10,40,70]

*/

int main() {
    string a, b, c;
    while (cin >> a >> b >> c) {
        vector<int> va = stringToVector(a);
        vector<int> vb = stringToVector(b);
        vector<int> vc = stringToVector(c);
        Solution sol;
        cout << sol.jobScheduling(va, vb, vc) << endl;
    }
    return 0;
}
#endif