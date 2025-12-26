/*
 * @Author: LetMeFly
 * @Date: 2025-12-26 18:39:14
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-12-26 18:42:18
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int bestClosingTime(string customers) {
        int maxium = 0, ans = 0;
        for (char c : customers) {
            maxium += c == 'Y';
        }
        int thisCost = maxium;
        for (int i = 0; i < customers.size(); i++) {
            if (customers[i] == 'Y') {
                thisCost--;
            } else {
                thisCost++;
            }
            if (thisCost < maxium) {
                maxium = thisCost;
                ans = i + 1;
            }
        }
        return ans;
    }
};