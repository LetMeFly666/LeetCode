/*
 * @Author: LetMeFly
 * @Date: 2023-08-22 09:13:46
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-08-22 09:29:09
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    bool canChange(string& a, string& b) {
        int n = a.size();
        int ia = -1, ib = -1;
        while (ia + 1 < n && ib + 1 < n) {
            while (++ia < n && a[ia] == '_');
            while (++ib < n && b[ib] == '_');
            if (a[ia] != b[ib]) {
                return false;
            }
            if (a[ia] == 'L') {
                if (ia < ib) {
                    return false;
                }
            }
            else {  // R
                if (ia > ib) {
                    return false;
                }
            }
        }
        while (ia + 1 < n) {
            if (a[++ia] != '_') {
                return false;
            }
        }
        while (ib + 1 < n) {
            if (b[++ib] != '_') {
                return false;
            }
        }
        return true;
    }
};

#ifdef _WIN32
/*
_L__R__R_
L______RR

true
*/

/*
R_L_
__LR

false
*/

/*
_R
R_

false
*/
int main() {
    string a, b;
    while (cin >> a >> b) {
        Solution sol;
        cout << sol.canChange(a, b) << endl;
    }
    return 0;
}
#endif