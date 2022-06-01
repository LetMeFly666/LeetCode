/*
 * @Author: LetMeFly
 * @Date: 2022-06-01 09:53:22
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-06-01 10:51:38
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

#ifdef FirstTry
// TLE
class Solution {
private:
    /* 当前状态下已构成th条边是否可行 */
    bool ok(vector<int>& matchsticks, vector<bool>& visited, int l, int thisLength, int th) {
        if (thisLength > l) {
            return false;
        }
        if (thisLength == l) {
            th++;
            thisLength = 0;
            if (th == 4) {
                bool allVisited = true;
                for (bool b : visited) {
                    if (!b) {
                        allVisited = false;
                        break;
                    }
                }
                if (allVisited) {
                    return true;
                }
            }
        }
        for (int i = 0; i < matchsticks.size(); i++) {
            if (!visited[i]) {
                visited[i] = true;
                if (ok(matchsticks, visited, l, thisLength + matchsticks[i], th)) {
                    return true;
                }
                visited[i] = false;
            }
        }
        return false;
    }
public:
    bool makesquare(vector<int>& matchsticks) {
        int s = 0;
        for (int& t : matchsticks) {
            s += t;
        }
        int l = s / 4;  // 边长
        vector<bool> visited(matchsticks.size(), false);
        return ok(matchsticks, visited, l, 0, 0);
    }
};
#else  // FirstTry
// Copy
class Solution {
public:
    bool makesquare(vector<int>& matchsticks) {
        int totalLen = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        if (totalLen % 4 != 0) {
            return false;
        }
        int len = totalLen / 4, n = matchsticks.size();
        vector<int> dp(1 << n, -1);
        dp[0] = 0;
        for (int s = 1; s < (1 << n); s++) {
            for (int k = 0; k < n; k++) {
                if ((s & (1 << k)) == 0) {
                    continue;
                }
                int s1 = s & ~(1 << k);
                if (dp[s1] >= 0 && dp[s1] + matchsticks[k] <= len) {
                    dp[s] = (dp[s1] + matchsticks[k]) % len;
                    break;
                }
            }
        }
        return dp[(1 << n) - 1] == 0;
    }
};
#endif

#ifdef _WIN32
int main() {
    string s;
    while (cin >> s) {
        vector<int> v = stringToVector(s);
        Solution sol;
        cout << sol.makesquare(v) << endl;
    }
    return 0;
}
#endif