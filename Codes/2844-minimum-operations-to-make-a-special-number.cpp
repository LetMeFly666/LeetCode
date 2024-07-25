/*
 * @Author: LetMeFly
 * @Date: 2024-07-25 16:19:55
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-07-25 16:36:15
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    int thisEnd(string& s, int n) {
        int i = s.size() - 1;
        char finding = n % 10 + '0';
        while (i >= 0 && s[i] != finding) {
            i--;
        }
        i--;
        finding = n / 10 % 10 + '0';
        while (i >= 0 && s[i] != finding) {
            i--;
        }
        return i == -1 ? s.size() : s.size() - i - 2;
    }
public:
    int minimumOperations(string& s) {
        int ans = s.find('0') == string::npos ? s.size() : s.size() - 1;
        ans = min(ans, min(
            thisEnd(s, 0), min(
                thisEnd(s, 25), min(
                    thisEnd(s, 50), thisEnd(s, 75)
                )
            )
        ));
        return ans;
    }
};

#ifdef _WIN32
int main() {
    string s = "2245047";  // 2
    Solution sol;
    cout << sol.minimumOperations(s) << endl;
    return 0;
}
#endif