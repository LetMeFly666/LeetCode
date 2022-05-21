/*
 * @Author: LetMeFly
 * @Date: 2022-05-03 13:51:58
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-05-03 14:13:12
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    static bool isString(const string& s) {
        bool space = false;
        for (const char& c : s) {
            if (c == ' ') {
                space = true;
            }
            else {
                if (space) {
                    return c >= 'a' && c <= 'z';
                }
            }
        }
        return false;  // Fake Return
    }

    static int firstSpace(const string& s) {
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') {
                return i;
            }
        }
        return -1;  // Fake Return
    }

    static bool cmp(const string& a, const string& b) {  // 只排字符串
        int fsa = firstSpace(a);  // first space of a
        int fsb = firstSpace(b);  // first space of a
        if (a.substr(fsa + 1, a.size() - fsa - 1) == b.substr(fsb + 1, b.size() - fsb - 1)) {
            return a.substr(0, fsa) < b.substr(0, fsb);
        }
        else {
            return a.substr(fsa + 1, a.size() - fsa - 1) < b.substr(fsb + 1, b.size() - fsb - 1);
        }
    }
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string> ans;
        for (string& s : logs) {
            if (isString(s)) {
                ans.push_back(s);
            }
        }
        sort(ans.begin(), ans.end(), cmp);
        for (string& s : logs) {
            if (!isString(s)) {
                ans.push_back(s);
            }
        }
        return ans;
    }
};