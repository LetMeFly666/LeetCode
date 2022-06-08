/*
 * @Author: LetMeFly
 * @Date: 2022-06-08 10:32:10
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-06-08 11:25:21
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

bool isInteger(string& s) {
    if (s.empty())  // 空串
        return false;
    if (s.size() == 1 && (s[0] == '+' || s[0] == '-'))  // 只有±号
        return false;
    if (s[0] != '+' && s[0] != '-' && !(s[0] >= '0' && s[0] <= '9'))  // 第一个字符非法
        return false;
    for (int i = 1; i < s.size(); i++) {
        if (!(s[i] >= '0' && s[i] <= '9'))
            return false;
    }
    return true;
}

/*
    最多一个'.'
    最多一个'+'，如果有，一定是在串首
    最多一个'-'，如果有，一定是在串首
    最少一个数字
    无其他字符
*/
bool isDecimal(string& s) {
    int cntDot = 0;
    int cntAdd = 0;
    int cntDec = 0;
    int cntNum = 0;
    for (char& c : s) {
        if (c >= '0' && c <= '9')
            cntNum++;
        else if (c == '.')
            cntDot++;
        else if (c == '+')
            cntAdd++;
        else if (c == '-')
            cntDec++;
        else
            return false;
    }
    if (cntDot > 1)
        return false;
    if (cntAdd) {
        if (cntAdd > 1)
            return false;
        if (s[0] != '+')
            return false;
    }
    if (cntDec) {
        if (cntDec > 1)
            return false;
        if (s[0] != '-')
            return false;
    }
    return cntNum > 0;
}



class Solution {
public:
    bool isNumber(string& s) {
        int loce = s.find('e');
        int locE = s.find('E');
        if (loce == locE) {  // 无e且无E  // 这是一个小巧的做法，等效于 (loce == string::npos && locE == string::npos)
            return isInteger(s) || isDecimal(s);
        }
        // 有e或有E
        if (locE == string::npos)
            locE = loce;
        if (locE == s.size() - 1)
            return false;
        string front = s.substr(0, locE);
        string back = s.substr(locE + 1, s.size() - locE - 1);
        return (isInteger(front) || isDecimal(front)) && isInteger(back);
    }
};


#ifdef _WIN32
int main() {
    string s;
    while (cin >> s) {
        Solution sol;
        cout << sol.isNumber(s) << endl;
    }
    return 0;
}
#endif