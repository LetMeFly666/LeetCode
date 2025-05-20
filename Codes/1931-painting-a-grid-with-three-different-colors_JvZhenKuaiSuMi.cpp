/*
 * @Author: LetMeFly
 * @Date: 2025-05-20 08:59:53
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-05-20 09:17:44
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

typedef vector<vector<int>> matrix;

class Solution {
private:
    static constexpr int pow[6] = {1, 3, 9, 27, 81, 243};

    inline int getTh(int a, int n) {
        return a / pow[n] % 3;
    }

    inline bool isOk(int a, int m) {
        for (int i = 1; i < m; i++) {
            if (getTh(a, i) == getTh(a, i - 1)) {
                return false;
            }
        }
        return true;
    }
public:
    int colorTheGrid(int m, int n) {
        vector<int> singleOk;
        for (int i = 0; i < pow[m]; i++) {
            printf("isOk(%d, %d) = %d\n", i, m, isOk(i, m));
            if (isOk(i, m)) {
                singleOk.push_back(i);
            }
        }
        int singleNum = singleOk.size();  // 即使m=5也一共有48种
        return singleNum;
    }
};