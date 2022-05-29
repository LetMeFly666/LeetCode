/*
 * @Author: LetMeFly
 * @Date: 2022-05-29 08:08:36
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-05-29 08:58:43
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    string validIPAddress(string& queryIP) {
        int cntPoint = 0, cntColon = 0;
        for (char& c : queryIP) {
            cntPoint += c == '.';
            cntColon += c == ':';
        }
        if (cntPoint == 3) {
            queryIP += '.';  // 为了判断最后一个
            string thisNum;
            for (char& c : queryIP) {
                if (c == '.') {
                    if (thisNum.size() > 1 && thisNum[0] == '0') {  // 前导零
                        return "Neither";
                    }
                    if (thisNum.size() == 0 || thisNum.size() > 3) {  // 空或长度过长
                        return "Neither";
                    }
                    // 开始计算这个数的数值是多少
                    int num = 0;
                    for (char& cInNum : thisNum) {
                        if (cInNum >= '0' && cInNum <= '9') {
                            num *= 10;
                            num += cInNum - '0';
                        }
                        else {  // 非数字字符
                            return "Neither";
                        }
                    }
                    // 看这个数是否在[0, 255]范围内
                    if (num > 255) {
                        return "Neither";
                    }
                    thisNum = "";
                }
                else {
                    thisNum += c;
                }
            }
            return "IPv4";
        }
        else if (cntColon == 7) {
            queryIP += ':';
            string thisNum;
            for (char& c : queryIP) {
                if (c == ':') {
                    if (thisNum.size() == 0 || thisNum.size() > 4) {  // 看长度是否合法
                        return "Neither";
                    }
                    for (char& cInNum : thisNum) {
                        if (!(cInNum >= '0' && cInNum <= '9' || cInNum >= 'a' && cInNum <= 'f' || cInNum >= 'A' && cInNum <= 'F')) {
                            return "Neither";
                        }
                    }
                    thisNum = "";
                }
                else {
                    thisNum += c;
                }
            }
            return "IPv6";
        }
        return "Neither";
    }
};

/*
"172.16.254.1"
"2001:0db8:85a3:0:0:8A2E:0370:7334"
"1.0.1."
"1.1.1.01"

*/

#ifdef _WIN32
int main() {
    string s;
    while (cin >> s) {
        if (s[0] == '"') {
            s = s.substr(1, s.size() - 1);
        }
        if (s[s.size() - 1] == '"') {
            s = s.substr(0, s.size() - 1);
        }
        cout << s << endl;
        Solution sol;
        cout << sol.validIPAddress(s) << endl;
    }
    return 0;
}
#endif