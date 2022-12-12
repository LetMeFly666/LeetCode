/*
 * @Author: LetMeFly
 * @Date: 2022-12-12 11:12:13
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-12-12 11:51:09
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

#ifdef FirstTry  // 前缀和
class Solution {
public:
    int beautySum(string s) {
        int n = s.size();
        vector<vector<int>> prefix(26, vector<int>(n + 1));
        for (int i = 1; i <= n; i++) {
            for (int c = 0; c < 26; c++) {
                prefix[c][i] = prefix[c][i - 1];
            }
            prefix[s[i - 1] - 'a'][i]++;
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int M = 0, m = 1000;
                for (int c = 0; c < 26; c++) {
                    int thisC = prefix[c][j + 1] - prefix[c][i];
                    M = max(M, thisC);
                    if (thisC) {  // 不能出现0次
                        m = min(m, thisC);
                    }
                }
                // printf("i = %d, j = %d, M = %d, m = %d\n", i, j, M, m);  //***********
                ans += M - m;
            }
        }
        return ans;
    }
};
#else  // FirstTry
// SecondTry
class Solution {
public:
    int beautySum(string s) {
        int ans = 0;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            int cnt[26] = {0};
            for (int j = i; j < n; j++) {
                cnt[s[j] - 'a']++;
                int M = 0, m = 1000;
                for (int d = 0; d < 26; d++) {
                    M = max(M, cnt[d]);
                    if (cnt[d])
                        m = min(m, cnt[d]);
                }
                ans += M - m;
            }
        }
        return ans;
    }
};
#endif  // FirstTry