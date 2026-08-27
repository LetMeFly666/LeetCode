/*
 * @Author: LetMeFly
 * @Date: 2026-08-27 13:33:53
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-08-27 13:57:03
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    string lexGreaterPermutation(string& s, string& target) {
        int cnt[26] = {0};
        for (char c : s) {
            cnt[c - 'a']++;
        }
        
        bool alreadyBigger = false;
        for (int i = 0, n = target.size(); i < n; i++) {
            if (alreadyBigger) {  // 找最小的
                for (int j = 0; j < 26; j++) {
                    if (cnt[j]) {
                        cnt[j]--;
                        s[i] = j + 'a';
                        break;
                    }
                }
                continue;
            }

            // 尽量一样大
            if (cnt[target[i] - 'a']) {
                cnt[target[i] - 'a']--;
                s[i] = target[i];
                continue;
            }

            // 没有一样大的，看看有没有更大的
            bool found = false;
            for (int j = target[i] - 'a'; j < 26; j++) {
                if (target[j]) {
                    target[j]--;
                    s[i] = j + 'a';
                    alreadyBigger = true;
                    found = true;
                    break;
                }
            }

            // 也没有更大的了 比如s:124 target:125，走到4/5这里其实可以回退把s变成142
            if (!found) {
                for (int j = i - 1; j >= 0; j--) {
                    cnt[s[j] - 'a']++;
                    for (int k = target[i] - 'a'; k < 26; k++) {
                        if (cnt[k]) {
                            cnt[k]--;
                            s[j] = k + 'a';
                            alreadyBigger = true;
                            break;
                        }
                    }
                    if (alreadyBigger) {
                        break;
                    }
                }
                if (!alreadyBigger) {
                    return "";
                }
            }
        }
        return s;
    }
};
