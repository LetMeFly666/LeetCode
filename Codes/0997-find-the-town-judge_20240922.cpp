/*
 * @Author: LetMeFly
 * @Date: 2024-09-22 23:21:53
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-09-22 23:30:43
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

#ifdef FirstTry  // WA，并不是法官外的所有人都只相信法官(1信法官3且信2是可行的)
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        int ans = 0;
        for (vector<int>& v : trust) {
            printf("ans = %d, v[1] = %d\n", ans, v[1]);  //*********
            if (ans && ans != v[1]) {
                return -1;
            }
            ans = v[1];
        }
        return ans ? ans : 1;
    }
};
#else  // FirstTry
// SecondTry
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> inDegree(n + 1), outDegree(n + 1);
        for (vector<int>& v : trust) {
            inDegree[v[1]]++, outDegree[v[0]]++;
        }
        for (int i = 1; i <= n; i++) {
            if (inDegree[i] == n - 1 && outDegree[i] == 0) {
                return i;
            }
        }
        return -1;
    }
};
#endif  // FirstTry