/*
 * @Author: LetMeFly
 * @Date: 2023-11-23 10:11:09
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-11-23 10:19:03
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

const static vector<pair<string, char>> dic = {
    {"&quot;", '"'},
    {"&apos;", '\''},
    {"&amp;", '&'},
    {"&gt;", '>'},
    {"&lt;", '<'},
    {"&frasl;", '/'}
};

class Solution {
public:
    string entityParser(string& text) {
        string ans;
        for (int i = 0; i < text.size(); i++) {
            if (text[i] == '&') {
                for (auto&& [from, to] : dic) {
                    if (text.substr(i, from.size()) == from) {
                        ans += to;
                        i += from.size() - 1;
                        goto loop;
                    }
                }
            }
            ans += text[i];
            loop:;
        }
        return ans;
    }
};