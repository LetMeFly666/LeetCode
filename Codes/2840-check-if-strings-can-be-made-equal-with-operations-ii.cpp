/*
 * @Author: LetMeFly
 * @Date: 2026-03-30 09:25:57
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-03-30 09:28:44
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    bool checkStrings(const string& s1, const string& s2) {
        int n = s1.size();
        string odd1, odd2, even1, even2;
        odd1.reserve(n / 2);
        odd2.reserve(n / 2);
        even1.reserve(n / 2);
        even2.reserve(n / 2);
        for (int i = 0; i < n; i++) {
            if (i % 2) {
                odd1.push_back(s1[i]);
                odd2.push_back(s2[i]);
            } else {
                even1.push_back(s1[i]);
                even2.push_back(s2[i]);
            }
        }
        sort(odd1.begin(), odd1.end());
        sort(odd2.begin(), odd2.end());
        sort(even1.begin(), even1.end());
        sort(even2.begin(), even2.end());
        return odd1 == odd2 && even1 == even2;
    }
};