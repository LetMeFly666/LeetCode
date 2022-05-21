/*
 * @Author: LetMeFly
 * @Date: 2022-05-07 09:47:14
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-05-07 09:54:47
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

#ifdef FirstTry
// 其实题目更为复杂
class Solution {
public:
    int myAtoi(string s) {
        // return stoi(s);
        int ans = 0;
        int k = 1;
        for (char& c : s) {
            if (c == '-') {
                k = -1;
            }
            else if (c >= '0' && c <= '9') {
                ans *= 10;
                ans += c - '0';
            }
        }
        return k * ans;  // 这样会不会超INT_MAX
    }
};
#else
// Copy from Leetcode，自动机
class Automaton {
    string state = "start";
    unordered_map<string, vector<string>> table = {
        {"start", {"start", "signed", "in_number", "end"}},
        {"signed", {"end", "end", "in_number", "end"}},
        {"in_number", {"end", "end", "in_number", "end"}},
        {"end", {"end", "end", "end", "end"}}
    };

    int get_col(char c) {
        if (isspace(c)) return 0;
        if (c == '+' or c == '-') return 1;
        if (isdigit(c)) return 2;
        return 3;
    }
public:
    int sign = 1;
    long long ans = 0;

    void get(char c) {
        state = table[state][get_col(c)];
        if (state == "in_number") {
            ans = ans * 10 + c - '0';
            ans = sign == 1 ? min(ans, (long long)INT_MAX) : min(ans, -(long long)INT_MIN);
        }
        else if (state == "signed")
            sign = c == '+' ? 1 : -1;
    }
};

class Solution {
public:
    int myAtoi(string str) {
        Automaton automaton;
        for (char c : str)
            automaton.get(c);
        return automaton.sign * automaton.ans;
    }
};
#endif