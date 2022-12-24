/*
 * @Author: LetMeFly
 * @Date: 2022-12-24 10:06:35
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-12-24 10:44:40
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

#define FirstTry
// 方法一略优于方法二,但是Error了
#ifdef FirstTry  // 双指针
class Solution {
public:
    string largestMerge(string word1, string word2) {
        string ans;
        int loc1 = 0, loc2 = 0;
        while (loc1 < word1.size() && loc2 < word2.size()) {
            if (word1[loc1] != word2[loc2]) {
                if (word1[loc1] > word2[loc2])
                    ans += word1[loc1], word1 = word1.substr(1);
                else
                    ans += word2[loc2], word2 = word2.substr(1);
                continue;
            }
            int temp1 = loc1, temp2 = loc2;
            bool firstBigger = false;
            while (temp1 < word1.size() && temp2 < word2.size() && word1[temp1] == word2[temp2]) {
                temp1++, temp2++;
            }
            if (temp1 == word1.size()) {
                firstBigger = false;
            }
            else if (temp2 == word2.size()) {
                firstBigger = true;
            }
            else {
                firstBigger = word1[temp1] > word2[temp2];
            }
            if (firstBigger) {
                ans += word1.substr(loc1, temp1 - loc1);
                loc1 = temp1;
            }
            else {
                ans += word2.substr(loc2, temp2 - loc2);
                loc2 = temp2;
            }
        }
        if (loc1 < word1.size())
            ans += word1.substr(loc1);
        if (loc2 < word2.size())
            ans += word2.substr(loc2);
        return ans;
    }
};
#else  // FirstTry
// SecondTry  // 贪心
class Solution {
public:
    string largestMerge(string word1, string word2) {
        string ans;
        while (word1.size() && word2.size()) {
            if (word1 > word2) {
                ans += word1[0];
                word1 = word1.substr(1);
            }
            else {
                ans += word2[0];
                word2 = word2.substr(1);
            }
        }
        if (word1.size())
            ans += word1;
        if (word2.size())
            ans += word2;
        return ans;
    }
};
#endif  // FirstTry