/*
 * @Author: LetMeFly
 * @Date: 2023-05-17 09:03:57
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-05-17 09:15:35
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif


#ifdef FirstTry  // 让第一个开始时间不晚于第二个 + 字符串转整数
inline int convertTime(string& s) {
    return (s[0] - '0') * 600 + (s[1] - '0') * 60 + (s[3] - '0') * 10 + (s[4] - '0');
}

class Solution {
public:
    bool haveConflict(vector<string>& event1, vector<string>& event2) {
        int t1s = convertTime(event1[0]), t1e = convertTime(event1[1]);  // t1 start, t1 end
        int t2s = convertTime(event2[0]), t2e = convertTime(event2[1]);
        if (t1s > t2s) {  // 令第一个开始时间不晚于第二个
            swap(t1s, t2s);
            swap(t1e, t2e);
        }
        return t2s <= t1e;
    }
};
#else  // FirstTry
// SecondTry // 直接开始比较
class Solution {
public:
    bool haveConflict(vector<string>& event1, vector<string>& event2) {
        return !(event1[1] < event2[0] || event2[1] < event1[0]);
    }
};
#endif  // FirstTry