/*
 * @Author: LetMeFly
 * @Date: 2026-06-24 12:51:01
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-06-26 20:44:02
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

/*
up2[i] = sum(down[l..i-1])
down2[i] = sum(up[i+1..r])

n行m列 x m行p列 -> n行p列
n行1列 x 1行1列 -> n行1列
n行1列 x 1行n列 -> n行n列
1行n列 x n行n列 -> 1行n列

     down     X       MAT      ->      up2
                                    l l+1 ... r
                   0 1 ... 1
l l+1 ... r   X    0 0 ... 1   ->   0  l  ... sum[l..r-1]
                   .........
                   0 0 ... 0

      up      X       MAT2     ->                down2
                                         l          l+1     ... r
                   0 0 ... 0
l l+1 ... r   X    1 0 ... 0   ->   sum[l+1..r] sum[l+2..r] ... 0
                   .........
                   1 1 ... 0
*/
typedef long long ll;
ll MOD = 1e9 + 7;

class Matrix {
private:
    vector<vector<ll>> matrix;
public:
    Matrix(int n, int m) {
        matrix = vector<vector<ll>>(n, vector<ll>(m));
    }

    // 注意，这个会返回单位矩阵而非全0矩阵，若需nxn的全0矩阵请调用matrix(n, n)
    Matrix(int n) {
        matrix = vector<vector<ll>>(n, vector<ll>(n));
        for (int i = 0; i < matrix.size(); i++) {
            matrix[i][i] = 1;
        }
    }

    Matrix(const vector<vector<ll>>& other) {
        matrix = other;
    }

    // 禁止修改matrix[i]的长度
    vector<ll>& operator[](size_t i) {
        return matrix[i];
    }

    const vector<ll>& operator[](size_t i) const {
        return matrix[i];
    }

    // 需要保证matrix[i].size()==other.size()，为了运行效率此处不做断言
    Matrix operator*(const Matrix& other) const {
        int n = matrix.size(), m = matrix[0].size(), p = other[0].size();
        Matrix ans(n, p);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < p; j++) {
                for (int k = 0; k < m; k++) {
                    ans[i][j] = (ans[i][j] + matrix[i][k] * other[k][j]) % MOD;
                }
            }
        }
        return ans;
    }

    Matrix pow(int n) const {
        Matrix a = Matrix(matrix);
        Matrix ans = Matrix(matrix.size());
        while (n) {
            if (n & 1) {
                ans = ans * a;
            }
            a = a * a;
            n >>= 1;
        }
        return ans;
    }

    size_t size() const {
        return matrix.size();
    }
};

class Solution {
private:
    Matrix buildMAT(int n) {
        Matrix res = Matrix(n, n);
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                res[i][j] = 1;
            }
        }
        return res;
    }

    Matrix buildMAT2(int n) {
        Matrix res = Matrix(n, n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                res[i][j] = 1;
            }
        }
        return res;
    }

    Matrix buildUpDown(int n) {
        Matrix res = Matrix(1, n);
        for (int i = 0; i < n; i++) {
            res[0][i] = 1;
        }
        return res;
    }
public:
    int zigZagArrays(int n, int l, int r) {
        Matrix MAT = buildMAT(r - l + 1);
        Matrix MAT2 = buildMAT2(r - l + 1);
        Matrix MATA = MAT * MAT2;
        Matrix toMul = MATA.pow(n / 2);
        if (n % 2) {
            toMul = toMul * MAT;
        }
        Matrix up = buildUpDown(r - l + 1);
        Matrix matrixAns = up * toMul;
        ll ans = 0;
        for (int i = 0; i < matrixAns[0].size(); i++) {
            ans += matrixAns[0][i];
        }
        return ans * 2 % MOD;
    }
};

#ifdef _DEBUG
/*
3 4 5

2
*/
int main() {
    int a, b, c;
    while (cin >> a >> b >> c) {
        Solution sol;
        cout << sol.zigZagArrays(a, b, c) << endl;
    }
    return 0;
}
#endif
