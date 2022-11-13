/*
 * @Author: LetMeFly
 * @Date: 2022-11-13 10:19:47
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-11-13 10:24:00
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

int char2th[26];

bool cmp(const char& a, const char& b) {
    return char2th[a - 'a'] < char2th[b - 'a'];
}

class Solution {
private:
    void init(string& order) {
        for (int i = order.size() - 1; i >= 0; i--)
            char2th[order[i] - 'a'] = i;
    }
public:
    string customSortString(string& order, string& s) {
        init(order);
        sort(s.begin(), s.end(), cmp);
        return s;
    }
};