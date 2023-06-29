/*
 * @Author: LetMeFly
 * @Date: 2023-06-30 07:25:34
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-06-30 07:25:35
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    bool isCircularSentence(string sentence) {
        for (int i = 0; i < sentence.size(); i++) {
            if (sentence[i] == ' ') {
                if (sentence[i - 1] != sentence[i + 1]) {
                    return false;
                }
            }
        }
        return sentence.back() == sentence[0];
    }
};