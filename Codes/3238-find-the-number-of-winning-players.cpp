/*
 * @Author: LetMeFly
 * @Date: 2024-11-23 09:54:19
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2024-11-23 10:14:02
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

#ifdef FirstTry  // WA - new出来的值是随机值
class Solution {
public:
    int winningPlayerCount(int n, vector<vector<int>>& pick) {
        // int* cnt = new int[n];
        // for (vector<int>& p : pick) {
        //     cnt[p[0]]
        // }
        int (*cnt)[11] = new int[n][11];
        for (vector<int>& p : pick) {
            cnt[p[0]][p[1]]++;
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= 10; j++) {
                printf("cnt[%d][%d] = %d\n", i, j, cnt[i][j]);  //**************
                if (cnt[i][j] > i) {
                    ans++;
                    break;
                }
            }
        }
        // delete []cnt;
        return ans;
    }
};
#else  // FirstTry
// SecondTry
class Solution {
public:
    int winningPlayerCount(int n, vector<vector<int>>& pick) {
        int cnt[10][11] = {0};
        for (vector<int>& p : pick) {
            cnt[p[0]][p[1]]++;
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 11; j++) {
                if (cnt[i][j] > i) {
                    ans++;
                    break;
                }
            }
        }
        return ans;
    }
};
#endif  // FirstTry