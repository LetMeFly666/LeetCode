/*
 * @Author: LetMeFly
 * @Date: 2025-03-16 21:01:38
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-16 21:01:59
 */
#include <string>
typedef long long ll;
class Solution {
private:
    string itos(int n) {
        string s;
        while (n) {
            s = char('0' + n % 10) + s;
            n /= 10;
        }
        return s;
    }

    ll stoi(string s) {
        ll ans = 0;
        for (char c : s) {
            ans = ans * 10 + c - '0';
        }
        return ans;
    }
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param N int整型 
     * @return int整型

     12334
     12343

     12343
     12433

     1235
     */
    int nextGreaterElement(int N) {
        // write code here
        string s = itos(N);
        int last = -1;
        for (int i = 1; i < s.size(); i++) {
            if (s[i] > s[i - 1]) {
                last = i;
            }
        }
        if (last == -1) {
            return -1;
        }
        swap(s[last], s[last - 1]);
        // cout << s << endl;
        sort(s.begin() + last, s.end());
        // cout << s << endl;
        ll ans = stoi(s);
        cout << ans << endl;
        if (ans > INT_MAX) {
            return -1;
        }
        return ans;
    }
};