/*
 * @Author: LetMeFly
 * @Date: 2022-06-04 09:07:40
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-06-04 09:13:20
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> se;
        for (string& s : emails) {
            string realEmail;
            bool added = false;  // 出现过‘+’
            for (int i = 0; i < s.size(); i++) {
                char c = s[i];
                if (c == '@') {
                    realEmail += s.substr(i, s.size() - i);
                    break;
                }
                else if (c == '+') {
                    added = true;
                }
                if (!added && c != '.') {
                    realEmail += c;
                }
            }
            se.insert(realEmail);
        }
        return se.size();
    }
};