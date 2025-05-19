/*
 * @Author: LetMeFly
 * @Date: 2025-05-19 21:52:57
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-05-19 22:45:33
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    static constexpr int pow[6] = {1, 3, 9, 27, 81, 243};

    inline int getTh(int a, int n) {
        return a / pow[n] % 3;
    }

    bool ok(int a, int b, int m) {
        if (a % 3 == b % 3) {
            return false;
        }
        for (int i = 1; i < m; i++) {
            if (getTh(a, i) == getTh(b, i) || getTh(a, i) == getTh(a, i - 1) || getTh(b, i) == getTh(b, i - 1)) {
                return false;
            }
        }
        return true;
    }
public:
    int colorTheGrid(int m, int n) {
        int types = pow[m];
        unordered_map<int, int> okList;
        for (int i = 0; i < types; i++) {
            for (int j = 0; j < types; j++) {
                if (ok(i, j, m)) {
                    okList[i]++;
                }
            }
        }
        int ok1type = okList.size();
        unordered_map<int, int> firstCol(ok1type), secondCol(ok1type);
        for (unordered_map<int, int>::iterator it = okList.begin(); it != okList.end(); it++) {
            firstCol[it->first] = 1;
        }
        for (int j = 2; j <= n; j++) {
            
        }
    }
};