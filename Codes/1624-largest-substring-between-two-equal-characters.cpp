/*
 * @Author: LetMeFly
 * @Date: 2022-09-17 08:29:45
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-09-17 08:38:13
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

#ifdef FirstTry  // Error  // ababa选择的是第一个和第三个a，所选a不必相邻。
class Solution {
public:
    int maxLengthBetweenEqualCharacters(string& s) {
        int lastLoc[26];
        memset(lastLoc, -1, sizeof(lastLoc));
        int n = s.size();
        int ans = -1;
        for (int i = 0; i < n; i++) {
            int thisTh = s[i] - 'a';
            if (lastLoc[thisTh] != -1) {
                ans = max(ans, i - lastLoc[thisTh] - 1);
            }
            lastLoc[thisTh] = i;
        }
        return ans;
    }
};
#else  // FirstTry
class Solution {
public:
    int maxLengthBetweenEqualCharacters(string& s) {
        int n = s.size();
        vector<int> firstLoc(26, n);
        vector<int> lastLoc(26, -1);
        for (int i = 0; i < n; i++) {
            int th = s[i] - 'a';
            firstLoc[th] = min(firstLoc[th], i);
            lastLoc[th] = max(lastLoc[th], i);
        }
        int ans = -1;
        for (int i = 0; i < 26; i++) {
            if (firstLoc[i] != n) {
                ans = max(ans, lastLoc[i] - firstLoc[i] - 1);
            }
        }
        return ans;
    }
};
#endif  // FirstTry