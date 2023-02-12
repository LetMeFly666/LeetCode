/*
 * @Author: LetMeFly
 * @Date: 2023-02-12 09:34:54
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-02-12 09:55:32
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

#ifdef FirstTry  // 特判是否终点是z，如果终点是z则先左右移动后上下移动；否则先上下移动后左右移动即可

typedef pair<int, int> pii;

inline pii c2p(char c) {
    int th = c - 'a';
    return {th / 5, th % 5};
}

class Solution {
public:
    string alphabetBoardPath(string& target) {
        string ans;
        pii nowLoc = {0, 0};
        for (char c : target) {
            pii newLoc = c2p(c);
            if (c == 'z') {
                ans += string(abs(newLoc.second - nowLoc.second), newLoc.second > nowLoc.second ? 'R' : 'L');
                ans += string(abs(newLoc.first - nowLoc.first), newLoc.first > nowLoc.first ? 'D' : 'U');
            }
            else {
                ans += string(abs(newLoc.first - nowLoc.first), newLoc.first > nowLoc.first ? 'D' : 'U');
                ans += string(abs(newLoc.second - nowLoc.second), newLoc.second > nowLoc.second ? 'R' : 'L');
            }
            ans += '!';
            nowLoc = newLoc;
        }
        return ans;
    }
};

#else  // FirstTry
// SecondTry  // 四个方向分别判断，优先先左上移动后右下移动即可
typedef pair<int, int> pii;

inline pii c2p(char c) {
    int th = c - 'a';
    return {th / 5, th % 5};
}

class Solution {
public:
    string alphabetBoardPath(string& target) {
        string ans;
        pii nowLoc = {0, 0};
        for (char c : target) {
            pii newLoc = c2p(c);
            if (newLoc.first < nowLoc.first)
                ans += string(nowLoc.first - newLoc.first, 'U');
            if (newLoc.second < nowLoc.second)
                ans += string(nowLoc.second - newLoc.second, 'L');
            if (newLoc.first > nowLoc.first)
                ans += string(newLoc.first - nowLoc.first, 'D');
            if (newLoc.second > nowLoc.second)
                ans += string(newLoc.second - nowLoc.second, 'R');
            ans += '!';
            nowLoc = newLoc;
        }
        return ans;
    }
};
#endif  // FirstTry