/*
 * @Author: LetMeFly
 * @Date: 2022-03-02 14:40:25
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-03-03 14:18:29
 */
#ifdef RealSubmit

#ifdef _WIN32
#include "_[1,2]toVector.h"
#else
typedef long long ll;
#endif

class Solution {
public:
    string nearestPalindromic(string n) {
        if (n.size() == 1) {
            n[0] -= 1;
            return n;
        }
        vector<ll> condidates = {
            (ll)pow(10, n.size()) + 1,
            (ll)pow(10, n.size() - 1) - 1
        };
        string half = n.substr(0, (n.size() + 1) / 2);
        auto repair = [&](string qian){
            return qian + string(qian.rbegin() + (n.size() & 1), qian.rend());
        };
        for (int i = -1; i <= 1; i++) {
            condidates.push_back(stol(repair(to_string(stol(half) + i))));
        }
        ll m = 1e18, ans = -1;
        for (ll& thisAns : condidates) {
            // cout << thisAns << endl; //**************************
            if (thisAns != stol(n) && m >= abs(thisAns - stol(n))) {
                if (m == abs(thisAns - stol(n))) {
                    ans = min(ans, thisAns);
                }
                else {
                    m = abs(thisAns - stol(n));
                    ans = thisAns;
                }
            }
        }
        return to_string(ans);
    }
};

#ifdef _WIN32
int main() {
    string s;
    while (cin >> s) {
        Solution sol;
        cout << sol.nearestPalindromic(s) << endl;
    }
    return 0;
}
#endif

#else

typedef long long ll;

class Solution {
public:
    string nearestPalindromic(string n) {
        // 如果直接就是个位数，就返回n-1即可
        if (n.size() == 1) {
            n[0] -= 1;
            return n;
        }
        // 候选的答案（包括 99..99、100..001、前半部分+1做对称、前半部分不变做对称、前半部分-1做对称）
        vector<ll> condidates = {
            (ll)pow(10, n.size()) + 1,  // 100..001  例如99有2位，因此有候选答案101（10 ^ 2 + 1）
            (ll)pow(10, n.size() - 1) - 1  // 99..99  例如100有3位，因此就有候选答案99（10 ^ (3 - 1) - 1）
        };
        string half = n.substr(0, (n.size() + 1) / 2);  // 前半部分  如果是三位数就取2位，四位数也取1位，两位数就取1位，因此前半部分的长度是⌊(n.size() + 1) / 2⌋
        auto repair = [&](string qian){  // 由前半部分还原为整个数字的函数
            /* 
                整个数字：前半部分qian + {后半部分}
                    后半部分：
                        如果原数是奇数位，前半部分的最低位就不需要再重复一次(123的前半部分是12,还原成对称的整个数字是121,2不需要重复)
                        如果原数是偶数位，前半部分的最低为还需要重复一次(1234的前半部分是12,还原成1221,2需要重复)
                        因此原数字是奇数位的话前半部分的迭代器rbegin()+1正好跳过最低位，偶数rbegin()+0就正好包含了最低位
            */
            return qian + string(qian.rbegin() + (n.size() & 1), qian.rend());
        };
        for (int i = -1; i <= 1; i++) {  // 前半部分 +1、不变、-1
            /*
                stol(half)：前半部分(字符串)变成long long类型的数字
                stol(half) + i：前半部分 +1、不变 或 -1
                to_string(stol(half) + i)： repair函数接收的数据类型是string，因此把long long类型的数字变成string类型
                repair(to_string(stol(half) + i))：由前半部分还原出整个数字
                stol(repair(to_string(stol(half) + i)))：把repair函数返回的string类型的数字转换为long long类型
                condidates.push_back(stol(repair(to_string(stol(half) + i))))：将新的候选数字加入候选数字集合中
            */
            condidates.push_back(stol(repair(to_string(stol(half) + i))));
        }
        ll m = 1e18, ans = -1;  // m：新回文数 与 原数字 最小的diff  ans：答案
        for (ll& thisAns : condidates) {  // 对于所有的候选数字
            if (thisAns != stol(n) && m >= abs(thisAns - stol(n))) {  // 首先不是原数，其次这个diff不大于之前候选数字的最小diff
                if (m == abs(thisAns - stol(n))) {  // 如果这个diff正好等于之前的最小diff
                    ans = min(ans, thisAns); // 取最小的那个候选数字 （121 与 {111、131} 的 diff 都是10，但据题意我们需要更小的111）
                }
                else {  // 否则更新答案为 能使diff更小的这个候选数字
                    m = abs(thisAns - stol(n));
                    ans = thisAns;
                }
            }
        }
        return to_string(ans);  // 返回string类型的答案
    }
};

#endif