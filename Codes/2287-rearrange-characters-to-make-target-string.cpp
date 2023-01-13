/*
 * @Author: LetMeFly
 * @Date: 2023-01-13 15:37:27
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-01-13 15:40:38
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

#ifdef FirstTry  // 想着需要按顺序呢，错了，连顺序都不需要一致
class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        int ans = 0;
        int locT = 0;
        for (char c : s) {
            if (c == target[locT]) {
                locT++;
                if (locT == target.size()) {
                    locT = 0, ans++;
                }
            }
        }
        return ans;
    }
};
#else  // FirstTry
// SecondTry
class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        int cntS[26] = {0}, cntT[26] = {0};
        for (char c : s)
            cntS[c - 'a']++;
        for (char c : target)
            cntT[c - 'a']++;
        int ans = s.size();
        for (int i = 0; i < 26; i++) {
            if (cntT[i]) {
                ans = min(ans, cntS[i] / cntT[i]);
            }
        }
        return ans;
    }
};
#endif  // FirstTry