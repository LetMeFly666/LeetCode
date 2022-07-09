/*
 * @Author: LetMeFly
 * @Date: 2022-07-09 09:52:24
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-07-09 10:52:21
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

#ifdef FirstTry  // TLE
class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        unordered_set<int> number;
        set<pair<int, int>> diff;
        for (int &t : arr) {
            number.insert(t);
        }
        int ans = 0;
        for (int i = 0; i < arr.size(); i++) {
            for (int j = i + 1; j < arr.size(); j++) {
                int a = arr[i], b = arr[j];
                if (diff.count({a, b})) {
                    continue;
                }
                diff.insert({a, b});
                int thisAns = 2;
                int next = a + b;
                while (number.count(next)) {
                    thisAns++;
                    a = b, b = next, next = a + b;
                    if (diff.count({a, b})) {
                        continue;
                    }
                    diff.insert({a, b});
                }
                ans = max(ans, thisAns);
            }
        }
        return ans > 2 ? ans : 0;
    }
};
#else  // FirstTry
#ifdef SecondTry  // unordered_map
class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        unordered_map<int, int> ma;
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            ma[arr[i]] = i;
        }
        vector<vector<int>> dp(n, vector<int>(n, 2));
        int ans = 2;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int last = arr[j] - arr[i];
                if (ma.count(last)) {
                    int index = ma[last];
                    if (index < i) {
                        // dp[i][j] = max(dp[i][j], dp[index][i] + 1);
                        dp[i][j] = dp[index][i] + 1;
                        ans = max(ans, dp[i][j]);
                    }
                }
            }
        }
        return ans > 2 ? ans : 0;
    }
};
#else  // SecondTry
// ThirdTry  // Error
class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        unordered_set<int> se;
        for (int &t : arr) {
            se.insert(t);
        }
        vector<vector<int>> dp(n, vector<int>(n, 2));
        int ans = 2;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int last = arr[j] - arr[i];
                if (last < arr[i]) {
                    dp[i][j] = dp[last][i] + 1;  // Error，还是需要map来记录index
                    ans = max(ans, dp[i][j]);
                }
            }
        }
        return ans > 2 ? ans : 0;
    }
};
#endif  // SecondTry
#endif  // FirstTry