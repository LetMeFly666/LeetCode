/*
 * @Author: LetMeFly
 * @Date: 2025-05-14 09:36:25
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-05-14 23:47:59
 * @Description: AC,40.84%,94.37%
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

typedef long long ll;
typedef array<array<ll, 26>, 26> Matrix;

/*
    1 1 1 1 ... 2


*/

class Solution {
private:
    static const int MOD = 1000000007;
    
    Matrix Pow(Matrix a, int b) {
        Matrix ans{};
        for (int i = 0; i < 26; i++) {
            ans[i][i] = 1;
        }
        while (b) {
            if (b & 1) {
                ans = Mul(ans, a);
            }
            a = Mul(a, a);
            b >>= 1;
        }
        return ans;
    }

    Matrix Mul(Matrix& a, Matrix& b) {
        Matrix ans{};
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < 26; j++) {
                for (int k = 0; k < 26; k++) {
                    ans[i][k] = (ans[i][k] + a[i][j] * b[j][k] % MOD) % MOD;
                }
            }
        }
        return ans;
    }
public:
    int lengthAfterTransformations(string s, int t, vector<int>& nums) {
        Matrix M{};
        for (int i = 0; i < 26; i++) {
            for (int j = 1; j <= nums[i]; j++) {
                M[i][(i + j) % 26] = 1;
            }
        }
        M = Pow(M, t);
        ll cnt[26] = {0};
        for (char c : s) {
            cnt[c - 'a']++;
        }
        int ans = 0;
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < 26; j++) {
                ans = (ans + M[i][j] * cnt[i] % MOD) % MOD;
            }
        }
        return ans;
    }
};