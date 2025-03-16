/*
 * @Author: LetMeFly
 * @Date: 2025-03-16 22:52:13
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-16 22:53:13
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    vector<string> s2v(string s) {
        vector<string> ans;
        int last = -1;
        for (int i = 0; i <= s.size(); i++) {
            if (i == s.size() || s[i] == ' ') {
                string thisStr = s.substr(last + 1, i - last - 1);
                if (thisStr.size()) {
                    ans.push_back(thisStr);
                }
                last = i;
            }
        }
        return ans;
    }
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param pattern string字符串 
     * @param str string字符串 
     * @return bool布尔型
     */
    bool wordPattern(string pattern, string str) {
        // write code here
        unordered_map<char, string> p2s;
        unordered_map<string, char> s2p;
        vector<string> v = s2v(str);
        if (pattern.size() != v.size()) {
            return false;
        }
        for (int i = 0; i < v.size(); i++) {
            if (p2s.count(pattern[i])) {
                if (p2s[pattern[i]] != v[i]) {
                    return false;
                }
            } else {
                p2s[pattern[i]] = v[i];
            }

            if (s2p.count(v[i])) {
                if (s2p[v[i]] != pattern[i]) {
                    return false;
                }
            } else {
                s2p[v[i]] = pattern[i];
            }
        }
        return true;
    }
};