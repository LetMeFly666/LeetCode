/*
 * @Author: LetMeFly
 * @Date: 2025-04-19 22:10:42
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-05-13 22:46:25
 */
#include <bits/stdc++.h>
#include "2179.h"
using namespace std;

const int testTime = 10;
const int maxLengthPerTest = 20;

// 测试置换是否正确
class TestFT {
private:
    vector<int> a, b, p;

    void debug(vector<int>& a, string name) {
        cout << name << ":";
        for (int t : a) {
            cout << ' ' << t;
        }
        cout << endl;
    }

    bool isIn(int a, vector<int>& v) {
        for (int t : v) {
            if (a == t) {
                return true;
            }
        }
        return false;
    }
public:
    TestFT() {
        int n = rand() % maxLengthPerTest + 1;
        cout << "n = " << n << endl;
        for (int i = 0; i < n; i++) {
            while (true) {
                int t = rand() % n;
                // cout << "rand: " << t << " | ";
                // debug(a, "a");
                if (isIn(t, a)) {
                    continue;
                }
                a.push_back(t);
                break;
            }
            while (true) {
                int t = rand() % n;
                if (isIn(t, b)) {
                    continue;
                }
                b.push_back(t);
                break;
            }
        }
    }

    void P() {
        p.resize(a.size());
        for (int i = 0; i < a.size(); i++) {
            p[a[i]] = b[i];
        }
    }

    bool ok() {
        unordered_map<int, int> ma;
        for (int i = 0; i < a.size(); i++) {
            ma[a[i]] = b[i];
        }
        for (int i = 0; i < a.size(); i++) {
            if (ma[i] != p[i]) {
                return false;
            }
        }
        return true;
    }

    void info() {
        debug(a, "a");
        debug(b, "b");
        debug(p, "p");
    }
};

int main() {
    time_t start = clock();
    int cnt = 0;
    while (double(clock() - start) / CLOCKS_PER_SEC < testTime) {
        cnt++;
        TestFT test = TestFT();
        test.P();
        if (!test.ok()) {
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