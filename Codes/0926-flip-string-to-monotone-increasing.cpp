/*
 * @Author: LetMeFly
 * @Date: 2022-06-11 10:17:22
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-06-11 10:36:29
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n = s.size();
        vector<int> Qian0(n);  // Qian0[i]： 前i个全是0至少需要修改多少个
        vector<int> Hou1(n);  // Hou1[i]： 最后一个到第i个全是1至少需要修改多少个
        Qian0[0] = s[0] == '1';
        Hou1[n - 1] = s[n - 1] == '0';
        for (int i = 1; i < n; i++) {
            Qian0[i] = Qian0[i - 1] + (s[i] == '1');  // (s[i] == '1') 括号不能去
        }
        for (int i = n - 2; i >= 0; i--) {
            Hou1[i] = Hou1[i + 1] + (s[i] == '0');
        }
        int ans = min(Qian0[n - 1], Hou1[0]);  // 全0或全1
        for (int i = 0; i < n - 1; i++) {  // [0, i]变为0，[i + 1, n - 1]变为1
            ans = min(ans, Qian0[i] + Hou1[i + 1]);
        }
        return ans;
    }
};

/*
00110

*/
#ifdef _WIN32
int main() {
    string s;
    while (cin >> s) {
        Solution sol;
        cout << sol.minFlipsMonoIncr(s) << endl;
    }
    return 0;
}
#endif