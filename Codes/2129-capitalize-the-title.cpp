/*
 * @Author: LetMeFly
 * @Date: 2024-03-11 08:44:42
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-03-11 09:09:14
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

#ifdef FirstTry  // Error，没看到如果字母长度小于等于2则全小写
class Solution {
public:
    string capitalizeTitle(string title) {
        bool isFirst = true;
        for (char& c : title) {
            if (c == ' ') {
                isFirst = true;
                continue;
            }
            c = isFirst ? toupper(c) : tolower(c);
            isFirst = false;
        }
        return title;
    }
};
#else  // FirstTry
#ifdef SecondTry  // Error，句首单词也要遵循这个原则，“i love you”要转换成“i Love You”而不是“I Love You”
class Solution {
public:
    string capitalizeTitle(string title) {
        bool shouldUpper = true;
        for (int i = 0; i < title.size(); i++) {
            if (title[i] == ' ' && i + 3 < title.size() && title[i + 2] != ' ' && title[i + 3] != ' ') {
                shouldUpper = true;
                continue;
            }
            title[i] = shouldUpper ? toupper(title[i]) : tolower(title[i]);
            shouldUpper = false;
        }
        return title;
    }
};
#else  // SecondTry
// ThirdTry
class Solution {
public:
    string capitalizeTitle(string title) {
        bool shouldUpper = title.size() >= 3 && title[1] != ' ' && title[2] != ' ';
        for (int i = 0; i < title.size(); i++) {
            if (title[i] == ' ') {
                shouldUpper = i + 3 < title.size() && title[i + 2] != ' ' && title[i + 3] != ' ';
                continue;
            }
            title[i] = shouldUpper ? toupper(title[i]) : tolower(title[i]);
            shouldUpper = false;
        }
        return title;
    }
};
#endif  // SecondTry
#endif  // FirstTry