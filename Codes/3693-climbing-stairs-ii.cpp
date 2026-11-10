/*
 * @Author: LetMeFly
 * @Date: 2026-11-10 21:50:54
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-11-10 22:01:03
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

// 这里就写死大小为3了，不再支持大小为n的初始化了
class ABC {
private:
    int a[3] = {0};
    int diff = 0;
public:
    void push(int v) {
        a[diff] = v;
        diff = (diff + 1) % 3;
    }

    const int& operator[](int i) const {
        return a[(diff + i) % 3];
    }
};

class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        ABC abc;
        for (int cost : costs) {
            abc.push(cost + min(
                abc[0] + 9, min(
                    abc[1] + 4,
                    abc[2] + 1
                )
            ));
        }
        return abc[3];
    }
};
