/*
 * @Author: LetMeFly
 * @Date: 2022-10-15 10:57:52
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-10-15 11:07:21
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    string removeKdigits(string& num, int k) {
        stack<char> st;
        for (char c : num) {
            while (st.size() && k && st.top() > c) {
                st.pop();
                k--;
            }
            st.push(c);
        }
        while (k--) {
            st.pop();
        }
        // 转为字符串
        string ans;
        while (st.size()) {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        int front0 = 0;
        while (front0 < ans.size()) {
            if (ans[front0] == '0')
                front0++;
            else
                break;
        }
        if (front0 == ans.size()) {  // 全0
            ans = "0";
        }
        else {
            ans = ans.substr(front0, ans.size() - front0);
        }
        return ans;
    }
};

/*
1234567890 9

*/

#ifdef _WIN32
int main() {
    string s;
    int k;
    while (cin >> s >> k) {
        Solution sol;
        cout << sol.removeKdigits(s, k) << endl;
    }
    return 0;
}
#endif