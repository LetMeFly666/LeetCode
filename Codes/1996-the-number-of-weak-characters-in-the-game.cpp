/*
 * @Author: LetMeFly
 * @Date: 2022-01-28 10:50:04
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-01-28 10:51:33
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

#ifdef _WIN32
#else // LeetCode题解
class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        sort(begin(properties), end(properties), [](const vector<int> & a, const vector<int> & b) {
            return a[0] == b[0] ? (a[1] > b[1]) : (a[0] < b[0]);
        });
        stack<int> st;
        int ans = 0;
        for (auto & p: properties) {
            while (!st.empty() && st.top() < p[1]) {
                ++ans;
                st.pop();
            }
            st.push(p[1]);
        }
        return ans;
    }
};
#endif