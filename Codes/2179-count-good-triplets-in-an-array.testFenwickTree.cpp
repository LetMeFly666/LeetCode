/*
 * @Author: LetMeFly
 * @Date: 2025-04-19 22:10:42
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-05-13 23:52:00
 */
#include <bits/stdc++.h>
#include "2179-count-good-triplets-in-an-array.cpp"
using namespace std;

const int testTime = 10;
const int maxLengthPerTest = 200;
const int maxValPerNum = 200;
const int maxOpPerTest = 200;

class FT2 {
private:
    int n;
    vector<int> v;
public:
    FT2(int n): v(n + 1), n(n) {}

    FT2() {};

    void add(int a, int b) {
        while (a <= n) {
            v[a] += b;
            a += a & -a;
        }
    }

    int get(int a) {
        int ans = 0;
        while (a) {
            ans += v[a];
            a -= a & -a;
        }
        return ans;
    }

    vector<int>& debug_getV() {
        return v;
    }
};

// 测试置换是否正确
class TestFT {
private:
    struct Op {
        int a, b;  // v[a]增加b
        bool isAdd;
    };

    vector<int> v;
    vector<Op> opHistory;
    FT2 ft;
    int n;

    void debugOp(Op& op) {
        if (op.isAdd) {
            printf("v[%d] += %d\n", op.a, op.b);
        } else {
            printf("sum(v[1], ..., v[%d])\n", op.a);
        }
    }

    void debugVector(vector<int>& v, string name) {
        cout << name << ": ";
        debug(v);
    }
public:
    TestFT() {
        int n = rand() % maxLengthPerTest + 1;
        cout << "n = " << n << endl;
        v = vector<int>(n + 1);
        this->n = n;
        ft = FT2(n);
    }

    bool run() {
        int op = rand() % maxOpPerTest + 1;
        while (op--) {
            bool isAdd = rand() % 2;
            // cout << isAdd << endl;
            if (isAdd) {
                int a = rand() % n + 1;
                int b = rand() % maxValPerNum + 1;
                opHistory.push_back({a, b, isAdd});
                ft.add(a, b);
                v[a] += b;
            } else {
                int a = rand() % n + 1;
                opHistory.push_back({a, 0, isAdd});
                int result_ft = ft.get(a);
                int result_v = 0;
                for (int i = 1; i <= a; i++) {
                    result_v += v[i];
                }
                if (result_ft != result_v) {
                    return false;
                }
            }
            // debugOp(opHistory.back());
        }
        return true;
    }

    void info() {
        cout << "operation history: " << endl;
        for (Op& op : opHistory) {
            debugOp(op);
        }
        debugVector(v, "realV");
        debugVector(ft.debug_getV(), "ft.v");
    }
};

int main() {
    FenwickTree ft = FenwickTree(3);
    time_t start = clock();
    int cnt = 0;
    while (double(clock() - start) / CLOCKS_PER_SEC < testTime) {
        cnt++;
        TestFT test = TestFT();
        if (!test.run()) {
            test.info();
            break;
        }
    }
    cout << "total " << cnt << " tests in " << testTime << "s" << endl;
    return 0;
}

/*
total 656375 tests in 10s
没有发现assert failed
*/