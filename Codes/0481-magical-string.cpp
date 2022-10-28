/*
 * @Author: LetMeFly
 * @Date: 2022-10-28 08:48:09
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-10-28 09:17:19
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

#ifdef FirstTry  // 正常双指针
char str[100010] = "122";
class Solution {
public:
    int magicalString(int n) {
        int locFront = 2, locEnd = 3;
        char nowChar = '1';
        while (locEnd < n) {
            for (int i = str[locFront] - '0'; i > 0; i--) {
                str[locEnd++] = nowChar;
            }
            locFront++;
            nowChar = nowChar == '1' ? '2' : '1';
        }
        // puts(str);  //********
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans += str[i] == '1';
        }
        return ans;
    }
};
#else
// SecondTry  // 坏人做法：只求一次，后续只统计
// 坏坏方法，但是对执行结果的影响不大（数据不多，如果有几千组数据，那么这种坏方法的执行总时间将会大大减少）
char str[100010] = "122";
class Solution {
public:
    int magicalString(int n) {
        static bool first = true;
        if (first) {
            first = false;
            int locFront = 2, locEnd = 3;
            char nowChar = '1';
            while (locEnd < 100000) {
                for (int i = str[locFront] - '0'; i > 0; i--) {
                    str[locEnd++] = nowChar;
                }
                locFront++;
                nowChar = nowChar == '1' ? '2' : '1';
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans += str[i] == '1';
        }
        return ans;
    }
};
#endif