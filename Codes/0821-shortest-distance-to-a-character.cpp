/*
 * @Author: LetMeFly
 * @Date: 2022-04-19 10:08:41
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-04-19 10:18:03
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    string s;
    char e;
    int nowE = -1;
    int getNextE() {
        while (++nowE < s.size()) {
            if (s[nowE] == e) {
                return nowE;
            }
        }
        return s.size() * 2 + 1;
    }
public:
    vector<int> shortestToChar(string& s, char c) {
        this->s = s;
        this->e = c;
        int locE1 = -s.size() - 1;
        int locE2 = getNextE();
        vector<int> ans(s.size());
        for (int i = 0; i < s.size(); i++) {
            ans[i] = min(i - locE1, locE2 - i);
            if (i == locE2) {
                locE1 = locE2;
                locE2 = getNextE();
            }
        }
        return ans;
    }
};