/*
 * @Author: LetMeFly
 * @Date: 2025-03-16 20:52:35
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-16 20:52:36
 */
#include <unordered_map>
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
    bool testMatch(string pattern, string str) {
        // write code here
        unordered_map<char, string> ma;
        vector<string> v = s2v(str);
        if (pattern.size() != v.size()) {
            return false;
        }
        for (int i = 0; i < v.size(); i++) {
            if (ma.count(pattern[i])) {
                if (ma[pattern[i]] != v[i]) {
                    return false;
                }
            } else {
                ma[pattern[i]] = v[i];
            }
        }
        return true;
    }
};