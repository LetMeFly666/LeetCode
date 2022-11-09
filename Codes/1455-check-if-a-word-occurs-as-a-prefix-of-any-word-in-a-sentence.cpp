/*
 * @Author: LetMeFly
 * @Date: 2022-08-21 10:16:21
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-08-21 10:21:38
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int isPrefixOfWord(string& sentence, string& searchWord) {
        int locLong = 0, locShort = 0;
        int th = 1;  // 第几个单词
        while (locLong < sentence.size() && locShort < searchWord.size()) {
            if (sentence[locLong] == searchWord[locShort]) {
                locLong++, locShort++;
            }
            else {
                locShort = 0;
                while (locLong < sentence.size() && sentence[locLong] != ' ') {
                    locLong++;
                }
                locLong++;  // 空格后
                th++;
            }
            if (locShort == searchWord.size())
                return th;
        }
        return -1;
    }
};