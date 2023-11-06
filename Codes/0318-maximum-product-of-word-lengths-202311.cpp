/*
 * @Author: LetMeFly
 * @Date: 2023-11-06 20:03:36
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-11-06 20:09:17
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    int genMask(string& s) {
        int ans = 0;
        for (char c : s) {
            ans |= (1 << (c - 'a'));
        }
        return ans;
    }
public:
    int maxProduct(vector<string>& words) {
        unordered_map<int, int> ma;
        int ans = 0;
        for (string& s : words) {
            int mask = genMask(s);
            int length = s.size();
            for (auto&& [thatMask, thatLength] : ma) {
                if (!(mask & thatMask)) {
                    ans = max(ans, length * thatLength);
                }
            }
            ma[mask] = max(ma[mask], length);
        }
        return ans;
    }
};