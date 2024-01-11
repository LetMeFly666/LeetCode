/*
 * @Author: LetMeFly
 * @Date: 2024-01-11 15:23:29
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-01-11 15:34:45
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int addMinimum(string word) {
        int ans = 0;
        for (int i = 0; i < word.size(); i++) {
            if (word[i] == 'a') {  // axx abx abc ac
                if (i + 2 < word.size() && word[i + 1] == 'b' && word[i + 2] == 'c') {  // abc
                    i += 2;
                }
                else if (i + 1 < word.size() && word[i + 1] == 'c') {  // ac
                    i++;
                    ans++;
                }
                else if (i + 1 < word.size() && word[i + 1] == 'b') {  // abx
                    i++;
                    ans++;
                }
                else {  // axx
                    ans += 2;
                }
            }
            else if (word[i] == 'b') {  // xbx xbc
                if (i + 1 < word.size() && word[i + 1] == 'c') {  // xbc
                    i++;
                    ans++;
                }
                else {  // xbx
                    ans += 2;
                }
            }
            else {  // xxc
                ans += 2;
            }
        }
        return ans;
    }
};


#ifdef _WIN32
/*
aaaacc

a  a  a  a c  c
abcabcabcabcabc
*/
int main() {
    string s;
    while (cin >> s) {
        Solution sol;
        cout << sol.addMinimum(s) << endl;
    }
    return 0;
}
#endif