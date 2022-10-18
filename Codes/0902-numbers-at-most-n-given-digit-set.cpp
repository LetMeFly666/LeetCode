/*
 * @Author: LetMeFly
 * @Date: 2022-10-18 09:18:38
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-10-18 10:50:01
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

#ifdef FirstTry  // Error  // 每个数字可以选择任意次，不是一次
class Solution {
private:
    int ans;

    int A(int n, int m) {
        if (n < m)
            return 0;
        int ans = 1;
        for (int i = 0; i < m; i++) {
            ans *= n - i;
        }
        // for (int i = 0; i < m; i++) {
        //     ans /= i + 1;
        // }
        return ans;
    }

    void dfs(unordered_set<char>& unused, string nowString, int n) {
        if (nowString.size() == n) {
            if (atoll(nowString.c_str()) <= n)
                ans++;
        }
        else {
            for (char c : unused) {
                unordered_set<char> newSet = unused;
                newSet.erase(c);
                nowString += c;
                dfs(newSet, nowString, n);
                nowString.pop_back();
            }
        }
    }
public:
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        ans = 0;
        int len = to_string(n).size();
        for (int i = 1; i < len; i++) {
            printf("A(%d, %d) = %d\n", int(digits.size()), i, A(digits.size(), i));
            ans += A(digits.size(), i);
        }
        if (digits.size() >= len) {
            unordered_set<char> unused;
            for (string& d : digits) {
                unused.insert(d[0]);
            }
            dfs(unused, "", n);
        }
        return ans;
    }
};
#else  // FirstTry
// SecondTry
class Solution {
private:
    bool isIn(char c, vector<string>& digits) {
        for (string& s : digits) {
            if (c == s[0])
                return true;
        }
        return false;
    }

    int cntLessThan(char c, vector<string>& digits) {
        int ans = 0;
        for (string& s : digits) {
            if (s[0] < c)
                ans++;
        }
        return ans;
    }
public:
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        int ans = 0;
        int len = to_string(n).size();
        for (int i = 1; i < len; i++) {
            int cnt = digits.size();
            for (int j = 1; j < i; j++) {
                cnt *= digits.size();
            }
            ans += cnt;
        }
        string strify = to_string(n);
        // int cntEqual = 1;
        // for (int i = 0; i < len; i++) {
        //     if (cntEqual && !isIn(strify[i], digits)) {
        //         cntEqual = 0;
        //     }
        //     ans += (cntLessThan(strify[i], digits) + cntEqual) * pow(digits.size(), len - i - 1);
        // }
        int lessThan = cntLessThan(strify[0], digits), equal = isIn(strify[0], digits);
        for (int i = 1; i < len; i++) {
            lessThan = lessThan * digits.size() + equal * cntLessThan(strify[i], digits);;
            equal = equal * isIn(strify[i], digits);
        }
        ans += lessThan + equal;
        return ans;
    }
};
#endif  // FirstTry


#ifdef _WIN32
/*
["1","3","5","7"]
100

*/

/*
["1"]
834

*/
int main() {
    string s;
    int n;
    while (cin >> s >> n) {
        vector<string> v = stringToVectorString(s);
        for (string& s : v) {
            s = s.substr(1, 1);
        }
        Solution sol;
        cout << sol.atMostNGivenDigitSet(v, n) << endl;
    }
    return 0;
}
#endif