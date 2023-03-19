/*
 * @Author: LetMeFly
 * @Date: 2023-03-19 10:37:57
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-03-19 14:59:40
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

#ifdef FirstTry  // Error，不一定相邻两个数都能变换，如果“轮换”的值为偶数，则偶数下标上的数字永远不能得到变化
class Solution {
private:
    int add2minStep(char original, int a) {  // 将original加数次a，使得original尽可能小，需要加几次
        int ans = 0;
        int step = 0;
        int m = original - '0';
        int n = original - '0';
        do {
            n = (n + a) % 10;
            step++;
            if (n < m) {
                m = n;
                ans = step;
            }
        } while (a * step % 10);
        return ans;
    }

    string change2loc2min(string& s, int a, int l) {  // 将s的l、l + 1两个位置变得尽可能小并移动到最前
        int l1 = l, l2 = (l1 + 1) % s.size();
        int m1 = add2minStep(s[l1], a);
        int m2 = add2minStep(s[l2], a);
        string ans = s.substr(l, s.size() - l) + s.substr(0, l);
        for (int i = 0; i < s.size(); i += 2) {
            ans[i] = (char)((ans[i] - '0' + a * m1) % 10 + '0');
        }
        for (int i = 1; i < s.size(); i += 2) {
            ans[i] = (char)((ans[i] - '0' + a * m2) % 10 + '0');
        }
        return ans;
    }
public:
    string findLexSmallestString(string& s, int a, int b) {
        string ans = s;
        b %= s.size();
        int totalRotate = b;
        do {
            // string thisStr = change2loc2min(s, a, s.size() - totalRotate);  cout << thisStr << endl;  //**********
            ans = min(ans, change2loc2min(s, a, s.size() - totalRotate));
            totalRotate = (totalRotate + b) % s.size();
        } while (totalRotate != b);
        return ans;
    }
};
#else  // FirstTry
// SecondTry
class Solution {
private:
    int add2minStep(char original, int a) {  // 将original加数次a，使得original尽可能小，需要加几次
        int ans = 0;
        int step = 0;
        int m = original - '0';
        int n = original - '0';
        do {
            n = (n + a) % 10;
            step++;
            if (n < m) {
                m = n;
                ans = step;
            }
        } while (a * step % 10);
        return ans;
    }

    string change2loc2min(string& s, int a, int b, int l) {  // 将s的l、l + 1两个位置变得尽可能小并移动到最前
        string ans = s.substr(l, s.size() - l) + s.substr(0, l);
        if (b % 2) {
            int m1 = add2minStep(ans[0], a);
            for (int i = 0; i < s.size(); i += 2) {
                ans[i] = (char)((ans[i] - '0' + a * m1) % 10 + '0');
            }
        }
        int m2 = add2minStep(ans[1], a);
        for (int i = 1; i < s.size(); i += 2) {
            ans[i] = (char)((ans[i] - '0' + a * m2) % 10 + '0');
        }
        return ans;
    }
public:
    string findLexSmallestString(string& s, int a, int b) {
        string ans = s;
        int totalRotate = b;
        do {
            // string thisStr = change2loc2min(s, a, b, s.size() - totalRotate);  cout << thisStr << endl;  //**********
            ans = min(ans, change2loc2min(s, a, b, s.size() - totalRotate));
            totalRotate = (totalRotate + b) % s.size();
        } while (totalRotate != b);
        return ans;
    }
};
#endif  // FirstTry

#ifdef _WIN32
/*
74 5 1

*/

/*
565510 7 2

*/
int main() {
    // string a = "5525", b = "0030";
    // dbg((b < a));
    // a = min(a, b);
    // dbg(a);
    string s;
    int a, b;
    while (cin >> s >> a >> b) {
        Solution sol;
        cout << sol.findLexSmallestString(s, a, b) << endl;
    }
    return 0;
}
#endif