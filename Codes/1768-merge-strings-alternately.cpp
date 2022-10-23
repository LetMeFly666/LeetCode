/*
 * @Author: LetMeFly
 * @Date: 2022-10-23 09:02:52
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-10-23 09:04:01
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    string mergeAlternately(string& word1, string& word2) {
        int n1 = word1.size(), n2 = word2.size();
        int loc1 = 0, loc2 = 0;
        string ans;
        while (loc1 < n1 && loc2 < n2) {
            ans += word1[loc1++];
            ans += word2[loc2++];
        }
        while (loc1 < n1) {
            ans += word1[loc1++];
        }
        while (loc2 < n2) {
            ans += word2[loc2++];
        }
        return ans;
    }
};