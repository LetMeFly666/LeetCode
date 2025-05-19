/*
 * @Author: LetMeFly
 * @Date: 2025-05-19 21:52:57
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-05-19 23:11:19
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    static constexpr int pow[6] = {1, 3, 9, 27, 81, 243};
    static constexpr int MOD = 1e9 + 7;

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
        unordered_map<int, vector<int>> okList;
        for (int i = 0; i < types; i++) {
            for (int j = 0; j < types; j++) {
                if (ok(i, j, m)) {
                    okList[i].push_back(j);
                }
            }
        }
        int ok1type = okList.size();
        vector<int> firstCol(ok1type, 1), secondCol(ok1type);
        unordered_map<int, int> code2idx(ok1type);
        unordered_map<int, int> idx2code(ok1type);
        int th = 0;
        for (unordered_map<int, vector<int>>::iterator it = okList.begin(); it != okList.end(); it++, th++) {
            code2idx[it->first] = th;
            idx2code[th] = it->first;
        }
        for (int j = 2; j <= n; j++) {
            for (int t = 0; t < ok1type; t++) {
                int lastCode = idx2code[t];
                for (int nextCode : okList[lastCode]) {
                    secondCol[code2idx[nextCode]] = (secondCol[code2idx[nextCode]] + firstCol[t]) % MOD;
                }
            }
            firstCol = move(secondCol);
            secondCol = vector<int>(ok1type);
        }
        int ans = 0;
        for (int t : firstCol) {
            ans = (ans + t) % MOD;
        }
        return ans;
    }
};