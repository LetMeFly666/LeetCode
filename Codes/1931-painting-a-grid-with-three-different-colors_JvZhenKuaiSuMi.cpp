/*
 * @Author: LetMeFly
 * @Date: 2025-05-20 08:59:53
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-05-20 09:34:32
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

typedef long long ll;
typedef vector<vector<int>> matrix;

class Solution {
private:
    int singleNum;
    static constexpr int MOD = 1e9 + 7;
    static constexpr int pow[6] = {1, 3, 9, 27, 81, 243};

    inline int getTh(int a, int n) {
        return a / pow[n] % 3;
    }

    // 单看一列是否可行
    inline bool isOk(int a, int m) {
        for (int i = 1; i < m; i++) {
            if (getTh(a, i) == getTh(a, i - 1)) {
                return false;
            }
        }
        return true;
    }

    // 看可行的两列是否能相邻
    inline bool isOk(int a, int b, int m) {
        for (int i = 0; i < m; i++) {
            if (getTh(a, i) == getTh(b, i)) {
                return false;
            }
        }
        return true;
    }

    matrix mul(matrix a, matrix b) {
        matrix ans(singleNum, vector<int>(singleNum));
        for (int i = 0; i < singleNum; i++) {
            for (int k = 0; k < singleNum; k++) {
                for (int j = 0; j < singleNum; j++) {
                    ans[i][j] = (ans[i][j] + (ll)a[i][k] * b[k][j] % MOD) % MOD;
                }
            }
        }
        return ans;
    }

    matrix Pow(matrix a, int b) {
        matrix ans(singleNum, vector<int>(singleNum));
        for (int i = 0; i < singleNum; i++) {
            ans[i][i] = 1;
        }
        while (b) {
            if (b & 1) {
                ans = mul(ans, a);
            }
            a = mul(a, a);
            b >>= 1;
        }
        return ans;
    }
public:
    int colorTheGrid(int m, int n) {
        vector<int> singleOk;
        for (int i = 0; i < pow[m]; i++) {
            if (isOk(i, m)) {
                singleOk.push_back(i);
            }
        }
        singleNum = singleOk.size();  // 即使m=5也一共有48种
        // printf("%d\n", singleNum);
        matrix M(singleNum, vector<int>(singleNum));
        for (int i = 0; i < singleNum; i++) {
            for (int j = 0; j < singleNum; j++) {
                if (isOk(singleOk[i], singleOk[j], m)) {
                    M[j][i] = 1;
                }
            }
        }
        matrix Mn = Pow(M, n - 1);
        int ans = 0;
        for (int i = 0; i < singleNum; i++) {
            for (int j = 0; j < singleNum; j++) {
                ans = (ans + Mn[i][j]) % MOD;
            }
        }
        return ans;
    }
};