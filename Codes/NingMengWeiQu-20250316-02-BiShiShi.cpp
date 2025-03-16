/*
 * @Author: LetMeFly
 * @Date: 2025-03-16 20:53:22
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-16 20:53:22
 */
#include <string>
class Solution {
private:
    string itos(int n) {
        string s;
        while (n) {
            s = char('a' + n % 10) + s;
            n /= 10;
        }
        return s;
    }

    int stoi(string s) {
        int ans = 0;
        for (char c : s) {
            ans = ans * 10 + c - 'a';
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
    int findGreaterNum(int N) {
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
        sort(s.begin() + last + 1, s.end());
        return stoi(s);
    }
};