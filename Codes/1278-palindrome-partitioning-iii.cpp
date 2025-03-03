/*
 * @Author: LetMeFly
 * @Date: 2025-03-03 12:44:20
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-03 13:27:33
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    void testMinop(string& s, vector<vector<int>>& minop) {
        /*
        abc
        
        0 0
        0
        0 1
        1
        0 2
        1
        1 1
        0
        1 2
        1
        2 2 
        0
        */
        int l, r;  // [l, r]
        while (cin >> l >> r) {
            cout << minop[l][r] << endl;
        }
    }
public:
    int palindromePartition(string s, int k) {
        int n = s.size();
        vector<vector<int>> minop(n, vector<int>(n));
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                // printf("minop[%d][%d] = (s[%d] != s[%d]) + minop[%d][%d] =( %c != %c) + %d = %d\n", i, j, i, j, i + 1, j - 1, s[i], s[j], minop[i + 1][j - 1], (s[i] != s[j]) + minop[i + 1][j - 1]);  //*********
                minop[i][j] = (s[i] != s[j]) + minop[i + 1][j - 1];
            }
        }
        // testMinop(s, minop);
        vector<vector<int>> dp(n, vector<int>(k, 1000));  // 本身原本字符串长度就已经是1了，最多再切k-1次
        dp[0][0] = 0;
        for (int i = 0; i < n; i++) {
            dp[i][0] = minop[0][i];
        }
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < min(k, i + 1); j++) {
                for (int i0 = 0; i0 < i; i0++) {
                    // printf("dp[%d][%d] = min(dp[%d][%d], dp[%d][%d] + minop[%d][%d]) = min(%d, %d + %d) = %d\n", i, j, i, j, i0, j - 1, i0 + 1, i, dp[i][j], dp[i0][j - 1], minop[i0 + 1][i], min(dp[i][j], dp[i0][j - 1] + minop[i0 + 1][i]));  //****
                    dp[i][j] = min(dp[i][j], dp[i0][j - 1] + minop[i0 + 1][i]);
                }
            }
        }
        return dp.back().back();
    }
};

#ifdef _WIN32
/*
abc
2

1
*/
/*
aabbc
3

0
*/
/*
tcymekt
4

2
*/
/*
abab
3

1
*/
/*
leetcode
8

0
*/
int main() {
    string s;
    int k;
    while (cin >> s >> k) {
        Solution sol;
        cout << sol.palindromePartition(s, k) << endl;
    }
    return 0;
}
#endif