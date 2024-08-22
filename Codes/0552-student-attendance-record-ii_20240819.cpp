/*
 * @Author: LetMeFly
 * @Date: 2024-08-19 18:01:21
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-08-19 23:51:15
 */
// Half - error Version
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

// /*
// AL 0
// AP 1
// LA 2
// LL 3
// LP 4
// PA 5
// PL 6
// PP 7
// */

/*
A 0
L 1
P 2
*/
const int mod = 1e9 + 7;
class Solution {
public:
    int checkRecord(int n) {
        if (n == 1) {
            return 3;
        }
        int dp[3][3][2] = {0};
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (i == 0 && j == 0) {
                    continue;
                }
                if (i == 0 || j == 0) {
                    dp[i][j][1] = 1;
                }
                else {
                    dp[i][j][0] = 1;
                }
            }
        }

        for (int th = 3; th <= n; th++) {
            // int A = 0;  // 之前没有A即可
            // for (int i = 0; i < 3; i++) {
            //     for (int j = 0; j < 3; j++) {
            //         A = (A + dp[i][j][0]) % mod;
            //     }
            // }
            // int L = 0;  // 不是连续两次L即可
            // for (int i = 0; i < 3; i++) {
            //     for (int j = 0; j < 3; j++) {
            //         for (int k = 0; k < 2; k++) {
            //             if (i == 1 && j == 1) {
            //                 continue;
            //             }
            //             L = (L + dp[i][j][k]) % mod;
            //         }
            //     }
            // }
            // int P = 0;  // 一切即可
            // for (int i = 0; i < 3; i++) {
            //     for (int j = 0; j < 3; j++) {
            //         for (int k = 0; k < 2; k++) {
            //             P = (P + dp[i][j][k]) % mod;
            //         }
            //     }
            // }

            int temp[3][3][2];
            temp[0][0][0] = 0;  // AA0
            temp[0][0][1] = 0;  // AA1
            temp[0][1][0] = 0;  // AL0
            temp[0][1][1] = (dp[1][0][1] + dp[2][0][1]) % mod;  // AL1 = sum(*A1) = LA1+PA1
            temp[0][2][0] = 0;  // AP0
            temp[0][2][1] = (dp[1][0][1] + dp[2][0][1]) % mod;;  // AP1 = sum(*A1) = LA1+PA1
            temp[1][0][0] = 0;  // LA0
            temp[1][0][1] = (dp[1][1][1] + dp[2][1][1]) % mod;  // LA1 = LL0+PL0
            temp[1][1][0] = dp[2][1][0];  // LL0 = PL0
            temp[1][1][1] = (dp[2][1][1] + dp[0][1][1]) % mod;  // LL1 = PL1+AL1
            temp[1][2][0] = (dp[1][1][0] + dp[2][1][0]) % mod;  // LP0 = LL0+PL0
            temp[1][2][1] = ((dp[1][2][1] + dp[1][1][1]) % mod + dp[2][1][1]) % mod;  // LP1 = AL1+LL1+PL1
            temp[2][0][0] = 0;  // PA0
            temp[2][0][1] = (dp[1][2][0] + dp[2][2][0]) % mod;  // PA1 = LP0+PP0
            temp[2][1][0] = (dp[2][2][0] + dp[1][2][0]) % mod;  // PL0 = PP0+LP0
            temp[2][1][1] = ((dp[0][2][1] + dp[1][2][1]) % mod + dp[2][2][1]) % mod;  // PL1 = AP1+LP1+PP1
            temp[2][2][0] = (dp[1][2][0] + dp[2][2][0]) % mod;  // PP0 = LP0 + PP0
            temp[2][2][1] = ((dp[0][2][1] + dp[1][2][1]) % mod + dp[2][2][1]) % mod;  // PP1 = AP1+LP1+PP1;

            memcpy(dp, temp, sizeof(dp));
        }

        int ans = 0;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 2; k++) {
                    ans = (ans + dp[i][j][k]) % mod;
                }
            }
        }
        return ans;
    }
};

#ifdef _WIN32
int main() {
    int tests[][2] = {
        {1, 3},
        {2, 8},
        {3, 19}
    };
    return 0;
}
#endif