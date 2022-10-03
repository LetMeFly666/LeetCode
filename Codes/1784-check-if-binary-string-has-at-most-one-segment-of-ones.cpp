/*
 * @Author: LetMeFly
 * @Date: 2022-10-03 10:50:47
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-10-03 10:55:35
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

#ifdef FirstTry  // 统计连续1的个数
class Solution {
public:
    bool checkOnesSegment(string& s) {
        int cnt1 = 0;
        bool lastIs1 = false;
        for (char& c : s) {
            if (c == '0') {
                lastIs1 = false;
            }
            else {
                if (!lastIs1) {
                    lastIs1 = true;
                    cnt1++;
                }
            }
        }
        return cnt1 < 2;
    }
};
#else  // FirstTry
// SecondTry  // 找01是否存在
class Solution {
public:
    bool checkOnesSegment(string& s) {
        return s.find("01") == s.npos;
    }
};
#endif  // FirstTry