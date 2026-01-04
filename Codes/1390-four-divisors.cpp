/*
 * @Author: LetMeFly
 * @Date: 2026-01-04 13:32:09
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-01-04 18:42:03
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif
// THIS CANNOT BE ACCEPTED
class Solution {
private:
    static unordered_map<int, pair<int, int>> cache;

    pair<int, int> genWithTime(int n) {
        if (cache.count(n)) {
            return cache[n];
        }
        int k = sqrt(n);
        for (int i = 2; i <= k; i++) {
            if (n % i == 0) {
                auto[remainNum, remainSum] = genWithTime(n / i);
                return cache[n] = {remainNum + 1, remainSum + i};
            }
        }
        return cache[n] = {1, n};
    }

    int gen(int n) {
        if (cache.count(n)) {
            auto[num, sum] = cache[n];
            return num == 4 ? sum : 0;
        }
        int k = sqrt(n);
        for (int i = 2; i <= k; i++) {
            if (n % i == 0) {
                auto[remainNum, remainSum] = genWithTime(n / i);
                if (remainNum == 3) {
                    cache[n] = {4, i + remainSum};
                    return i + remainSum;
                }
                break;
            }
        }
        cache[n] = {4, 0};
        return 0;
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

unordered_map<int, pair<int, int>> Solution::cache;

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