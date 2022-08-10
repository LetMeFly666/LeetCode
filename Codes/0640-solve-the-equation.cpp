/*
 * @Author: LetMeFly
 * @Date: 2022-08-10 10:11:42
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-08-10 10:51:49
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    int getEqualLocation(string& s) {
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '=')
                return i;
        }
        return -1;  // Fake Return
    }

    int __LetMeFly_atoi(string& s, int left, int length) {
        if (length == 0) {
            return 1;
        }
        if (length == 1 && s[left] == '-') {
            return -1;
        }
        if (length == 1 && s[left] == '+') {
            return 1;
        }
        int k = 1;
        if (s[left] == '+')
            left++, length--;
        else if (s[left] == '-')
            left++, length--, k = -1;
        int ans = 0;
        while (length--) {
            ans *= 10;
            ans += s[left++] - '0';
        }
        return ans * k;
    }

    pair<int, int> getXandConst(string& s, int l, int r) {  // get [l, r) 's x and const
        pair<int, int> ans;
        int lastLoc = l;
        for (int nowLoc = l; nowLoc <= r; nowLoc++) {
            if (nowLoc != l && (nowLoc == r || s[nowLoc] == '+' || s[nowLoc] == '-')) {
                // (lastLoc, nowLoc)
                // (s[nowLoc - 1] == 'x' ? ans.first : ans.second) += atoi(s.substr(lastLoc, (s[nowLoc - 1] == 'x' ? nowLoc - 1 : nowLoc) - lastLoc).c_str());
                // printf("s.substr(%d, %d) = %s = %d\n", lastLoc, (s[nowLoc - 1] == 'x' ? nowLoc - 1 : nowLoc) - lastLoc, s.substr(lastLoc, (s[nowLoc - 1] == 'x' ? nowLoc - 1 : nowLoc) - lastLoc).c_str(), atoi(s.substr(lastLoc, (s[nowLoc - 1] == 'x' ? nowLoc - 1 : nowLoc) - lastLoc).c_str()));  //***************
                (s[nowLoc - 1] == 'x' ? ans.first : ans.second) += __LetMeFly_atoi(s, lastLoc, (s[nowLoc - 1] == 'x' ? nowLoc - 1 : nowLoc) - lastLoc);
                lastLoc = nowLoc;
            }
        }
        return ans;
    }
public:
    string solveEquation(string& equation) {
        int locEqual = getEqualLocation(equation);
        auto [leftX, leftConst] = getXandConst(equation, 0, locEqual);
        auto [rightX, rightConst] = getXandConst(equation, locEqual + 1, equation.size());
        if (leftX == rightX) {
            return leftConst == rightConst ? "Infinite solutions" : "No solution";
        }
        return "x=" + to_string((rightConst - leftConst) / (leftX - rightX));
    }
};

/*
x+5-3+x=6+x-2

x=2
*/

/*
-x=-1

x=1
*/
#ifdef _WIN32
int main() {
    dbg(atoi("+2"));
    dbg(atoi("-2"));
    dbg(atoi("+"));
    dbg(atoi("-"));
    dbg(atoi(""));
    
    puts("");

    puts("int x = 0, y = 0;");
    int x = 0, y = 0;
    puts("(true ? x : y) += 10;");
    (true ? x : y) += 10;
    printf("x = %d, y = %d\n", x, y);
    puts("(false ? x : y) += 5;");
    (false ? x : y) += 5;
    printf("x = %d, y = %d\n", x, y);
    puts("");

    string s;
    while (cin >> s) {
        Solution sol;
        cout << sol.solveEquation(s) << endl;
    }
    return 0;
}
#endif