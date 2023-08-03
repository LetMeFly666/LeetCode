/*
 * @Author: LetMeFly
 * @Date: 2023-08-03 07:54:37
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-08-03 08:03:01
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    vector<string> removeComments(vector<string>& source) {
        vector<string> ans;
        bool findingEnd = false;
        string thisLine;
        for (string& s : source) {
            for (int i = 0; i < s.size(); i++) {
                if (findingEnd) {
                    if (s[i] == '*' && i + 1 < s.size() && s[i + 1] == '/') {
                        findingEnd = false;
                        i++;
                    }
                }
                else {
                    if (s[i] == '/' && i + 1 < s.size() && s[i + 1] == '*') {
                        findingEnd = true;
                        i++;
                    }
                    else if (s[i] == '/' && i + 1 < s.size() && s[i + 1] == '/') {
                        break;
                    }
                    else {
                        thisLine += s[i];
                    }
                }
            }
            if (!findingEnd) {
                if (thisLine.size()) {
                    ans.push_back(thisLine);
                    thisLine.clear();
                }
            }
        }
        return ans;
    }
};