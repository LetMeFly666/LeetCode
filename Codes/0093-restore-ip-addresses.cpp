/*
 * @Author: LetMeFly
 * @Date: 2022-06-28 16:42:31
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-06-28 16:52:34
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    inline bool ifok(string& s) {
        if (s.empty())
            return false;
        if (s.size() > 3)  // Necessary，因为要不然atoi超int可能变成负值
            return false;
        if (s.size() > 1 && s[0] == '0')
            return false;
        return atoi(s.c_str()) < 256;
    }
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        for (int i = 0; i < (1 << s.size()); i++) {
            int cnt = 0;
            for (int j = 0; j < s.size(); j++) {
                if (i & (1 << j)) {
                    cnt++;
                }
            }
            if (cnt != 3)
                continue;
            string thisString;
            string thisPart;
            for (int j = 0; j < s.size(); j++) {
                thisPart += s[j];
                if (i & (1 << j)) {
                    if (ifok(thisPart)) {
                        thisString += thisPart + ".";
                        thisPart = "";
                    }
                    else {
                        goto loop;
                    }
                }
            }
            if (ifok(thisPart)) {
                thisString += thisPart;
            }
            else {
                goto loop;
            }
            ans.push_back(thisString);
            loop:;
        }
        return ans;
    }
};