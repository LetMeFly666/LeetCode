/*
 * @Author: LetMeFly
 * @Date: 2022-11-06 08:53:18
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-11-06 12:05:47
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

#ifdef FirstTry  // 两个多余变量模拟
class Solution {
public:
    int fib(int n) {
        if (n < 2)
            return n;
        int _0 = 0, _1 = 1;
        int ans;
        for (int i = 2; i <= n; i++) {
            ans = _0 + _1;
            _0 = _1, _1 = ans;
        }
        return ans;
    }
};
#else  // FirstTry
#ifdef SecondTry  // 开辟一整个数组
class Solution {
public:
    int fib(int n) {
        int a[31] = {0, 1};
        for (int i = 2; i <= n; i++)
            a[i] = a[i - 1] + a[i - 2];
        return a[n];
    }
};
#else  // SecondTry
#ifdef ThirdTry  // 递归
class Solution {
public:
    int fib(int n) {
        if (n < 2)
            return n;
        return fib(n - 1) + fib(n - 2);
    }
};
#else  // ThirdTry
#ifdef FourthTry  // 递归 + 记忆化
class Solution {
private:
    unordered_map<int, int> ma;
public:
    int fib(int n) {
        if (n < 2)
            return n;
        if (ma.count(n))
            return ma[n];
        return ma[n] = fib(n - 1) + fib(n - 2);
    }
};
#else  // FourthTry
#ifdef FifthTry  // 通项公式
class Solution {
public:
    int fib(int n) {
        return 1. / sqrt(5) * (pow((1 + sqrt(5)) / 2, n) - pow((1 - sqrt(5)) / 2, n));
    }
};
#else  // FifthTry
// SixthTry  // 矩阵快速幂
struct Matrix {
    int a[2][2];

    Matrix(int x, int y, int m, int n) {
        a[0][0] = x, a[0][1] = y;
        a[1][0] = m, a[1][1] = n;
    }

    Matrix() {
        a[0][0] = 0, a[0][1] = 0;
        a[1][0] = 0, a[1][1] = 0;
    }
};

Matrix operator* (const Matrix& a, const Matrix& b) {
    Matrix result;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            result.a[i][j] = a.a[i][0] * b.a[0][j] + a.a[i][1] * b.a[1][j];
        }
    }
    return result;
}

class Solution {
private:
    Matrix Pow(Matrix a, int n) {  // 这里只接受>0的n
        Matrix result(1, 0, 0, 1);
        while (n) {
            if (n & 1)
                result = result * a;
            n >>= 1;
            a = a * a;
        }
        return result;
    }
public:
    int fib(int n) {
        if (n < 2)
            return n;
        return Pow(Matrix(1, 1, 1, 0), n - 1).a[0][0];
    }
};
#endif  // FifthTry
#endif  // FourthTry
#endif  // ThirdTry
#endif  // SecondTry
#endif  // FirstTry