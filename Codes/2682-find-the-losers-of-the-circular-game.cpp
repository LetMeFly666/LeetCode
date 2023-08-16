/*
 * @Author: LetMeFly
 * @Date: 2023-08-16 08:29:24
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-08-16 08:41:30
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

#ifdef FirstTry  // firstTry，while可简化
class Solution {
public:
    vector<int> circularGameLosers(int n, int k) {
        vector<bool> visited(n, false);  // 0到n-1编号
        int who = 0, th = 0;
        while (true) {
            who = (who + th++ * k) % n;
            if (visited[who]) {
                break;
            }
            visited[who] = true;
        }
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                ans.push_back(i + 1);
            }
        }
        return ans;
    }
};
#else  // FirstTry
// SecondTry
class Solution {
public:
    vector<int> circularGameLosers(int n, int k) {
        vector<bool> visited(n);
        int who = 0, th = 0;
        while (!visited[who]) {
            visited[who] = true;
            who = (who + ++th * k) % n;
        }
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                ans.push_back(i + 1);
            }
        }
        return ans;
    }
};
#endif  // FirstTry