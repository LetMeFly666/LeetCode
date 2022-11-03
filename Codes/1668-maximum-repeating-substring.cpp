/*
 * @Author: LetMeFly
 * @Date: 2022-11-03 07:55:58
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-11-03 08:06:16
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int maxRepeating(string& sequence, string& word) {
        int ans = 0;
        string substring = word;
        // while (sequence.contains(substring)) {  // C20
        while (sequence.find(substring, 0) != string::npos) {
            ans++;
            substring += word;
        }
        return ans;
    }
};