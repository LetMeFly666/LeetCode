/*
 * @Author: LetMeFly
 * @Date: 2025-02-22 11:13:07
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-02-22 11:15:31
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    inline int code(string& s) {
        int ans = 0;
        for (char c : s) {
            ans |= 1 << (c - 'a');
        }
        return ans;
    }
public:
    int similarPairs(vector<string>& words) {
        unordered_map<int, int> ma;
        int ans = 0;
        for (string& s : words) {
            int c = code(s);
            ans += ma[c];
            ma[c]++;
        }
        return ans;
    }
};