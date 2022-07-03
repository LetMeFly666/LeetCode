/*
 * @Author: LetMeFly
 * @Date: 2022-07-03 10:40:48
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-07-03 10:59:44
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#else
typedef long long ll;
#endif

#ifdef FirstTry  // Error
class Solution {
public:
    int nextGreaterElement(int n) {
        string s = to_string(n);
        bool changed = false;
        for (int i = s.size() - 2; i >= 0; i--) {
            int m = 1000, locm = i;
            for (int j = i + 1; j < s.size(); j++) {
                if (s[j] > s[i] && s[j] <= m) {
                    m = s[j], locm = j;
                }
            }
            if (locm != i) {
                changed = true;
                swap(s[i], s[locm]);
                break;
            }
        }
        if (!changed)
            return -1;
        ll ans = atoll(s.c_str());
        if (ans > INT_MAX)
            return -1;
        return ans;
    }
};
#else  // FirstTry
// SecondTry
/*
    从后往前看，找到第一个“后面有大于它的数”的数（记为s[i] = x）
    在s[i ~ 最后]中找到最小的大于x的数（记为s[j]=y）
    交换s[i]和s[j]
    在s[i+1 ~ 最后]范围内从小到大排序
*/
class Solution {
public:
    int nextGreaterElement(int n) {
        string s = to_string(n);
        bool changed = false;
        for (int i = s.size() - 2; i >= 0; i--) {
            char m = 58;  // '9' = 57
            int locm = i;
            for (int j = i + 1; j < s.size(); j++) {
                if (s[j] > s[i] && s[j] < m) {
                    m = s[j];
                    locm = j;
                }
            }
            if (locm != i) {
                changed = true;
                swap(s[i], s[locm]);
                sort(s.begin() + i + 1, s.end());
                break;
            }
        }
        if (!changed)
            return -1;
        ll ans = atoll(s.c_str());
        if (ans > INT_MAX)
            return -1;
        return ans;
    }
};
#endif  // FirstTry

#ifdef _WIN32
int main() {
    int n;
    while (cin >> n) {
        Solution sol;
        cout << sol.nextGreaterElement(n) << endl;
    }
    return 0;
}
#endif