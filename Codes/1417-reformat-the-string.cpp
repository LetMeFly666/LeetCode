/*
 * @Author: LetMeFly
 * @Date: 2022-08-11 09:46:20
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-08-11 09:52:19
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    string reformat(string& s) {
        string C, N;
        for (char& c : s) {
            if (c >= 'a' && c <= 'z')
                C += c;
            else
                N += c;
        }
        if (abs(int(C.size() - N.size())) > 1)
            return "";
        bool shouldC = C.size() >= N.size();
        string ans;
        int locC = 0, locN = 0;
        while (locC < C.size() || locN < N.size()) {
            if (shouldC) {
                shouldC = false;
                ans += C[locC++];
            }
            else {
                shouldC = true;
                ans += N[locN++];
            }
        }
        return ans;
    }
};