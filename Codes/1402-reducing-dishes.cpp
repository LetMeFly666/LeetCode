/*
 * @Author: LetMeFly
 * @Date: 2023-10-22 15:48:44
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-10-22 16:08:50
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());
        int positiveLocation = upper_bound(satisfaction.begin(), satisfaction.end(), 0) - satisfaction.begin();
        int ans = 0, sumPositive = 0;
        for (int i = positiveLocation; i < satisfaction.size(); i++) {
            ans += (i - positiveLocation + 1) * satisfaction[i];
            sumPositive += satisfaction[i];
        }
        int sumNegative = 0;
        for (int i = positiveLocation - 1; i >= 0; i--) {
            sumNegative += satisfaction[i];
            if (-sumNegative > sumPositive) {
                break;
            }
            ans += sumPositive + sumNegative;
        }
        return ans;
    }
};

#ifdef _WIN32
void test(vector<int> v) {
    Solution sol;
    cout << sol.maxSatisfaction(v) << endl;
}

void test1() {
    vector<int> satisfaction = {-1, -8, 0, 5, -9};
    test(satisfaction);
}

void test2() {
    test({-1, -8, 0, 5, -7});
}

void test3() {
    test({4, 3, 2});
}

int main() {
    // test1();
    test2();
    // test3();
    return 0;
}
#endif