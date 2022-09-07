/*
 * @Author: LetMeFly
 * @Date: 2022-09-07 19:51:51
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-09-07 20:02:09
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    string reorderSpaces(string& text) {
        // count spaces
        int spaces = 0;
        int numOfWords = 0;
        bool lastIsSpace = true;
        for (char& c : text) {
            if (c == ' ') {
                spaces++;
                lastIsSpace = true;
            }
            else {
                if (lastIsSpace) {
                    lastIsSpace = false;
                    numOfWords++;
                }
            }

        }

        // calculate
        int perSpace, lastSpace;
        if (numOfWords == 1) {
            perSpace = 0;
            lastSpace = spaces;
        }
        else {
            perSpace = spaces / (numOfWords - 1);
            lastSpace = spaces % (numOfWords - 1);
        }

        // construct
        string ans;
        int nowWords = 0;
        for (int i = 0; i < text.size(); i++) {
            if (text[i] == ' ')
                continue;
            ans += text[i];
            if (i + 1 < text.size() && text[i + 1] == ' ') {  // 单词的最后一个字母
                nowWords++;
                if (nowWords != numOfWords) {
                    for (int j = 0; j < perSpace; j++) {
                        ans += ' ';
                    }
                }
            }
        }
        for (int i = 0; i < lastSpace; i++) {
            ans += ' ';
        }
        return ans;
    }
};