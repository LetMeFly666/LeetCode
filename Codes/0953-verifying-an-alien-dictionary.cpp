/*
 * @Author: LetMeFly
 * @Date: 2022-04-20 15:20:07
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-04-20 15:25:54
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    bool isAlienSorted(vector<string>& words, string& order) {
        int sunxu[26] = {0};
        for (int i = 0; i < 26; i++) {
            sunxu[order[i] - 'a'] = i;
        }
        auto less = [&sunxu](const string& a, const string& b) {
            int to = min(a.size(), b.size());
            for (int i = 0; i < to; i++) {
                if (sunxu[a[i] - 'a'] < sunxu[b[i] - 'a'])
                    return true;
                else if (sunxu[a[i] - 'a'] > sunxu[b[i] - 'a'])
                    return false;
            }
            return a.size() <= b.size();
        };
        for (int i = 1; i < words.size(); i++) {
            if (!less(words[i - 1], words[i]))
                return false;
        }
        return true;
    }
};