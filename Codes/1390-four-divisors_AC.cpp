/*
 * @Author: LetMeFly
 * @Date: 2026-01-04 13:32:09
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-01-04 18:47:21
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    static unordered_map<int, int> cache;

    int gen(int n) {
        if (cache.count(n)) {
            return cache[n];
        }

        int cnt = 0, sum = 0;
        int k = sqrt(n);
        if (k * k == n) {
            cnt = 1, sum = k;
        }
        for (int i = 1; i < k; i++) {
            if (n % i == 0) {
                cnt += 2;
                sum += i + n / i;
            }
        }
        return cache[n] = cnt == 4 ? sum : 0;
    }
public:
    int sumFourDivisors(vector<int>& nums) {
        int ans = 0;
        for (int t : nums) {
            ans += gen(t);
        }
        return ans;
    }
};

unordered_map<int, int> Solution::cache;

#if defined(_WIN32) || defined(__APPLE__)
/*
[21,4,7]
[16]
*/
int main() {
    string s;
    while (cin >> s) {
        vector<int> v = stringToVector(s);
        Solution sol;
        cout << sol.sumFourDivisors(v) << endl;
    }
    return 0;
}
#endif