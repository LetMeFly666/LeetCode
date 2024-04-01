/*
 * @Author: LetMeFly
 * @Date: 2024-04-01 16:32:26
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-04-01 16:34:48
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    string finalString(string s) {
        deque<char> q;
        bool push_front = false;
        for (char c : s) {
            if (c == 'i') {
                push_front = !push_front;
                continue;
            }
            if (push_front) {
                q.push_front(c);
            }
            else {
                q.push_back(c);
            }
        }
        return push_front ? string{q.rbegin(), q.rend()} : string{q.begin(), q.end()};
    }
};