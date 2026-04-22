/*
 * @Author: LetMeFly
 * @Date: 2026-04-22 23:07:22
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-04-22 23:09:06
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

class Solution {
inline bool ok(const string& a, const string& b) {
    int diff = 0;
    for (int i = 0; i < a.size(); i++) {
        diff += a[i] != b[i];
    }
    return diff <= 2;
}
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> ans;
        for (string& a : queries) {
            for (string& b : dictionary) {
                if (ok(a, b)) {
                    ans.push_back(a);
                }
            }
        }
        return ans;
    }
};
