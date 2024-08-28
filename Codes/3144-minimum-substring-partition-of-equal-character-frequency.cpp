/*
 * @Author: LetMeFly
 * @Date: 2024-08-28 22:46:53
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-08-28 23:09:20
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int minimumSubstringsInPartition(string& s) {
        vector<int> dp(s.size() + 1, 1000000);
        dp[0] = 0;
        unordered_map<char, int> ma;
        for (int i = 0; i < s.size(); i++) {
            ma.clear();
            int types = 0, maxTimes = 0;
            for (int j = i; j >= 0; j--) {
                maxTimes = max(maxTimes, ++ma[s[j]]);
                if (ma[s[j]] == 1) {
                    types++;
                }
                if (maxTimes * types == i - j + 1) {
                    dp[i + 1] = min(dp[i + 1], dp[j] + 1);
                }
            }
        }
        return dp.back();
    }
};

#ifdef _WIN32
int main() {
    Solution sol;
    string s = "fabccddg";
    cout << sol.minimumSubstringsInPartition(s) << endl;
    assert(sol.minimumSubstringsInPartition(s) == 3);
    return 0;
}
#endif