/*
 * @Author: LetMeFly
 * @Date: 2022-10-30 08:21:53
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-10-30 08:32:40
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

#ifdef FirstTry  // Error  // 虽然改变了，但是可能1a、1a重复
class Solution {
public:
    vector<string> letterCasePermutation(string& s) {
        vector<string> ans = {s};
        int to = 1 << s.size();
        for (int i = 0; i < to; i++) {
            string newS = s;
            bool changed = false;
            for (int j = 0; j < s.size(); j++) {
                if (i & (1 << j)) {
                    if (!(0 <= s[j] && s[j] <= '9')) {
                        newS[j] ^= 32;
                        changed = true;
                    }
                }
            }
            if (changed) {
                ans.push_back(newS);
            }
        }
        return ans;
    }
};
#else  // FirstTry
// SecondTry
class Solution {
public:
    vector<string> letterCasePermutation(string& s) {
        vector<int> charLoc;
        for (int i = 0; i < s.size(); i++) {
            if (!(s[i] >= '0' && s[i] <= '9')) {
                charLoc.push_back(i);
            }
        }
        vector<string> ans;
        int to = 1 << charLoc.size();
        for (int i = 0; i < to; i++) {
            ans.push_back(s);
            for (int j = 0; j < charLoc.size(); j++) {
                if (i & (1 << j)) {
                    ans.back()[charLoc[j]] ^= 32;
                }
            }
        }
        return ans;
    }
};
#endif  // FirstTry