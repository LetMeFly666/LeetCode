/*
 * @Author: LetMeFly
 * @Date: 2023-06-19 15:56:53
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-06-19 16:19:59
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Min2 {  // 最小的两个数（范围1-10^4）
private:
    int min1, min2;
    int num;
public:
    Min2() {
        min1 = min2 = num = 0;
    }

    void update(int n) {
        if (!num) {
            min1 = n;
            num = 1;
        }
        else if (num == 1) {
            min2 = n;
            num = 2;
            if (min1 > min2) {
                swap(min1, min2);
            }
        }
        else {
            if (n < min1) {
                min2 = min1;
                min1 = n;
            }
            else if (n < min2) {
                min2 = n;
            }
        }
    }

    int getMin1() {
        return min1;
    }

    int getMin2() {
        return min2;
    }

    int getMinNum() {
        return num;
    }
};

class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        Min2 mod1, mod2;
        int cnt = 0;
        for (int t : nums) {
            cnt += t;
            if (t % 3 == 1) {
                mod1.update(t);
            }
            else if (t % 3 == 2) {
                mod2.update(t);
            }
        }
        if (cnt % 3 == 0) {
            return cnt;
        }
        else if (cnt % 3 == 1) {  // 减去一个模为1的或两个模为2的
            if (mod1.getMinNum() < 1 && mod2.getMinNum() < 2) {
                return 0;
            }
            int ans = 0;
            if (mod1.getMinNum()) {
                ans = max(ans, cnt - mod1.getMin1());
            }
            if (mod2.getMinNum() >= 2) {
                ans = max(ans, cnt - mod2.getMin1() - mod2.getMin2());
            }
            return ans;
        }
        else {  // 减去一个模为2的或两个模为1的
            if (mod2.getMinNum() < 1 && mod1.getMinNum() < 2) {
                return 0;
            }
            int ans = 0;
            if (mod2.getMinNum()) {
                ans = max(ans, cnt - mod2.getMin1());
            }
            if (mod1.getMinNum() >= 2) {
                ans = max(ans, cnt - mod1.getMin1() - mod1.getMin2());
            }
            return ans;
        }
    }
};

#ifdef _WIN32
/*
[1,2,3,4,4]
*/
int main() {
    string s;
    while (cin >> s) {
        vector<int> v = stringToVector(s);
        Solution sol;
        cout << sol.maxSumDivThree(v) << endl;
    }
    return 0;
}
#endif