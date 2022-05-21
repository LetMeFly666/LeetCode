/*
 * @Author: LetMeFly
 * @Date: 2022-04-17 10:03:38
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-04-17 13:00:39
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#else
#define dbg(x) cout << #x << " = " << x << endl
#endif

#define isChar(a) (a >= 'a' && a <= 'z' || a >= 'A' && a <= 'Z')

class Solution {
public:
    string mostCommonWord(string& paragraph, vector<string>& banned) {
        for (char& c : paragraph) {
            if (c >= 'A' && c <= 'Z') {
                c ^= 32;
            }
        }
        // dbg(paragraph);
        map<string, int> ma;
        set<string> se;
        for (auto& s : banned) {
            se.insert(s);
        }
        int l = 0;
        bool lastIsChar = false;
        paragraph += '.';
        for (int r = 0; r < paragraph.size(); r++) {
            if (!lastIsChar && isChar(paragraph[r])) {
                l = r;
                lastIsChar = true;
            }
            else if (lastIsChar && !isChar(paragraph[r]) && !se.count(paragraph.substr(l, r - l))) {
                ma[paragraph.substr(l, r - l)]++;
                lastIsChar = false;
            }
            lastIsChar = isChar(paragraph[r]);
        }
        // for (auto[a, b] : ma) {
        //     cout << a << " : " << b << endl;
        // }
        string ans;
        int M = 0;
        for (auto& [thisString, thisAppendtime] : ma) {
            if (thisAppendtime > M) {
                M = thisAppendtime;
                ans = thisString;
            }
        }
        return ans;
    }
};